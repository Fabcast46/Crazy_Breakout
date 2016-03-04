#include "Thread.h"

Thread::Thread(qintptr ID, QObject *parent) :
    QThread(parent)
{
    this->socketDescriptor = ID;
}

/**
 * This method gets the information and will write it in the server
 * @brief Thread::readyRead
 */
void Thread::readyRead()
{
    // get the information
    QByteArray Data = socket->readAll();
    // will write on server side window
    qDebug() << socketDescriptor << " Data in: " << Data;
    socket->write(Data);
}

/**
 * This method will disconnect the server and client when the socket is lost or deleted.
 * @brief Thread::desconectado
 */
void Thread::desconectado()
{
    qDebug() << socketDescriptor << " Desconectado";
    socket->deleteLater();
    exit(0);
}

/**
 * Method that executes the thread, evaluates the ID and port number to connect succesfully.
 * @brief Thread::run
 */
void Thread::run()
{
    // thread starts
    qDebug() << " Thread iniciado";
    socket = new QTcpSocket();
    // set the ID
    if(!socket->setSocketDescriptor(this->socketDescriptor))
    {
        emit error(socket->error());
        return;
    }
    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()), Qt::DirectConnection);
    connect(socket, SIGNAL(desconectado()), this, SLOT(desconectado()));
    // We'll have multiple clients, we want to know which is which
    qDebug() << socketDescriptor << " Cliente conectado";

    exec();
}
