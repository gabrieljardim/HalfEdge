#include <QTextStream>
#include <QString>
#include <QDebug>
#include <QFile>
#include <QMap>

#include "io.h"
#include "face.h"
#include "vertex.h"

using namespace std;

QMap<Face*, QList<HalfEdge*>> face_edge_map;
QList<HalfEdge*> edge_list;
QList<Vertex*> vertex_list;
HalfEdge* edge;
Face* face;

int face_counter;

bool LeArquivo(const QString& filename, HalfEdge** out)
{
    QFile arqdat(filename);
    QString linha;
    QChar it;
    tok tag;

    face_edge_map.clear();
    vertex_list.clear();
    edge_list.clear();

    face_counter = -1;

    arqdat.open(QIODevice::ReadOnly);
    QTextStream stream(&arqdat);

    linha = stream.readLine();

    if(linha != "RT 1.0")
    {
        return false;
    }

    linha = stream.readLine();

    tag = tok_DESCONHECIDO;

    while(!linha.isEmpty())
    {
        QTextStream s(&linha, QIODevice::ReadOnly);
        QString tmp;

        it = linha.at(0);
        if (it == '#')
        {
            s >> tmp;
            tag = Token(tmp);
        }
        else if (it != ';' && it != '!')
        {
            LeInfo(tag, s);
        }

        linha = stream.readLine();
    }

    arqdat.close();

    *out = face_edge_map.first().at(0);

    return true;
}

tok Token(const QString& linha)
{
    if(linha == "#VERTEX") return tok_VERTEX;

    if(linha == "#FACE") return tok_FACE;

    if(linha == "#NEXT") return tok_NEXT;

    if(linha == "#TWIN") return tok_TWIN;

    return tok_DESCONHECIDO;
}

void LeInfo(tok tag, QTextStream& linha)
{
    QList<HalfEdge*> local_edge_list;
    int i, j, vertex_number;
    char p;

    switch(tag)
    {
        case tok_VERTEX:
            while (!linha.atEnd()) vertex_list.append(LeVertice(linha));

            return;
        case tok_FACE:
            face = new Face();

            while (!linha.atEnd())
            {
                linha >> vertex_number >> p;
                edge = new HalfEdge(face, new Vertex(*vertex_list.at(vertex_number - 1)));
                edge->vertex->edge = edge;

                if (local_edge_list.isEmpty()) face->edge = edge;
                local_edge_list.append(edge);
                edge_list.append(edge);
            }

            face_edge_map.insert(face, local_edge_list);

            return;
        case tok_NEXT:
            i = 0;

            while (!linha.atEnd())
            {
                linha >> vertex_number >> p;
                face_edge_map.value(face).at(i)->next = face_edge_map.value(face).at(vertex_number - 1);

                i++;
            }

            return;
        case tok_TWIN:
            i = 0;
            j = 0;
            face_counter++;

            while (!linha.atEnd())
            {
                linha >> vertex_number >> p;

                if (vertex_number != 0)
                {
                    for (QList<HalfEdge*> lst : face_edge_map.values())
                    {
                        if (j == face_counter)
                        {
                            lst.at(i)->twin = edge_list.at(vertex_number - 1);
                            break;
                        }

                        j++;
                    }
                }

                i++;
            }
    }

    return;
}

Vertex* LeVertice(QTextStream& linha)
{
    float x, y;
    char p;

    linha >> x >> p >> y >> p;

    return new Vertex(x, y);
}
