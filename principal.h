#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <QMainWindow>
#include <QMessageBox>
#include <QFileDialog>
#include <QFile>
#include <QFileInfoList>
#include <QDir>
#include <QDebug>
#include <QDate>
#include <QTextStream>

#include "usuario.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Principal; }
QT_END_NAMESPACE

class Principal : public QMainWindow
{
    Q_OBJECT

public:
    Principal(QWidget *parent = nullptr);
    ~Principal();

private slots:
    void on_cmdCalcular_clicked();

private:
    Ui::Principal *ui;
    QDate m_fecha;
    Usuario *m_usuario;
    void guardar();
    void limpiar();
};
#endif // PRINCIPAL_H
