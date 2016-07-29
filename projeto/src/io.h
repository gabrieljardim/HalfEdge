#include <QList>
#include <QString>
#include <QTextStream>

#include "halfedge.h"

typedef enum {
    tok_DESCONHECIDO = 0,
    tok_VERTEX,
    tok_FACE,
    tok_NEXT,
    tok_TWIN
}tok;

bool LeArquivo(const QString&, HalfEdge**);

tok Token(const QString &);

void LeInfo(tok i, QTextStream&);

Vertex* LeVertice(QTextStream&);
