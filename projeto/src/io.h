#include <QString>
#include <QTextStream>

#include "halfedge.h"

typedef enum {
  tok_DESCONHECIDO = 0,
  tok_FACE
}tok;

bool LeArquivo(const QString&, HalfEdge**);

tok Token(const QString &);

HalfEdge *LeInfo(tok i, QTextStream&);

Vertex* LePonto(QTextStream&);
