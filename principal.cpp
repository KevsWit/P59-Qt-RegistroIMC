#include "principal.h"
#include "ui_principal.h"

Principal::Principal(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Principal)
{
    ui->setupUi(this);
    QString nuevo = "registroIMCtest.txt";
    QString dirHome = QDir::home().absolutePath();
    QString nombreArchivo = dirHome + "/" + nuevo;
    qDebug() << "\nPath: " << nombreArchivo;
}

Principal::~Principal()
{
    delete ui;
}


void Principal::on_cmdCalcular_clicked()
{
    m_usuario->setPesoAct(ui->inPeso->value());
    m_usuario->setAltura(ui->inAltura->value());
    if (m_usuario->calcularIMC()){
        ui->outIMC->setText(QString::number(m_usuario->imc(), 'f', 2));
        if(m_usuario->imc() < 18.5){
            ui->outObservacion->setText("Bajo peso");
        }else if(m_usuario->imc() >= 18.5 && m_usuario->imc() < 25.0){
            ui->outObservacion->setText("Normal");
        }else if(m_usuario->imc() >= 25.0 && m_usuario->imc() < 30){
            ui->outObservacion->setText("Sobrepeso");
        }else{
            ui->outObservacion->setText("Obesidad");
        }
    }else{
        if (m_usuario->altura() == 0 && m_usuario->pesoAct() == 0)
            QMessageBox::warning(this,"Advertencia","El peso y la altura son cero");
        else if (m_usuario->altura() == 0)
            QMessageBox::warning(this,"Advertencia","La altura es cero");
        else
            QMessageBox::warning(this,"Advertencia","El peso es cero");
    }
}

