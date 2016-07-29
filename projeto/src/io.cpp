#include <QTextStream>
#include <QString>
#include <QFile>
#include <list>

#include "io.h"
#include "face.h"
#include "vertex.h"

using namespace std;

bool LeArquivo(const QString& filename, HalfEdge** out)
{
    QFile arqdat(filename);
    tok tag;
    QString linha;
    QChar it;

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
            *out = LeInfo(tag, s);
        }

        linha = stream.readLine();
    }

    arqdat.close();

    return true;
}

tok Token(const QString& linha)
{
    if(linha == "#FACE") return tok_FACE;

    return tok_DESCONHECIDO;
}

HalfEdge* LeInfo(tok tag, QTextStream& linha)
{
    Face* face;
    Vertex* vertex;
    //List<HalfEdge*> vertex_list;

    switch(tag)
    {
        case tok_FACE:
            face = new Face();

            vertex = LePonto(linha);
            HalfEdge* edge1 = new HalfEdge(face, vertex, nullptr, nullptr);

            vertex = LePonto(linha);
            HalfEdge* edge2 = new HalfEdge(face, vertex, nullptr, nullptr);

            vertex = LePonto(linha);
            HalfEdge* edge3 = new HalfEdge(face, vertex, nullptr, nullptr);

            edge1->vertex->edge = edge1;
            edge2->vertex->edge = edge2;
            edge3->vertex->edge = edge3;

            face->edge = edge1;
            edge1->next = edge2;
            edge2->next = edge3;
            edge3->next = edge1;

            return edge1;
    }

    return nullptr;
}

Vertex* LePonto(QTextStream& linha)
{
    float x, y;
    char p;

    linha >> x >> p >> y >> p;

    return new Vertex(x, y);
}
