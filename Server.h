#ifndef SERVER
#define SERVER

#include <QTcpServer>
#include "Thread.h"

class Server : public QTcpServer
{
    Q_OBJECT
public:
    explicit Server(QObject *parent = 0);
    void startServer();

public slots:

protected:
    void incomingConnection(qintptr socketDescriptor);

signals:
};
#endif // SERVER
