#include <QCoreApplication>
#include <QSerialPort>
#include <QTimer>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // Create a QSerialPort object
    QSerialPort serial;
    serial.setPortName("/dev/ttyAMA0"); // Use the appropriate UART device file
    serial.setBaudRate(QSerialPort::Baud19200);// Set the baud rate
    serial.setDataBits(QSerialPort::Data8);
    serial.setParity(QSerialPort::NoParity);
    serial.setStopBits(QSerialPort::OneStop);
    serial.setFlowControl(QSerialPort::NoFlowControl);

    if(serial.isOpen())
    {
        QByteArray ba = writeDataString.toUtf8();
        char  *write_buffer = ba.data();
        //int noofByteWritten = serialport.write(write_buffer,sizeof(write_buffer));
        int noofByteWritten = serialport.write(write_buffer);
        serialport.waitForBytesWritten(100);
        if(noofByteWritten>0)
        {
            success = true;
        }
    }else{

    }

    return a.exec();
}
