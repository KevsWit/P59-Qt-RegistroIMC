#include "principal.h"
#include "ui_principal.h"

Principal::Principal(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Principal)
{
    ui->setupUi(this);
    QString nuevo = "registroIMC.txt";
    QString dirHome = QDir::home().absolutePath();
    QString nombreArchivo = dirHome + "/" + nuevo;
    QFile archivo(nombreArchivo);
    if(archivo.open(QFile::ReadOnly)){
        QTextStream entrada(&archivo);
        float mayor = 0, menor = 0;
        do{
            QString linea = entrada.readLine();
            int pos1 = linea.indexOf('o')+2;
            int pos2 = linea.indexOf('k')-1;
            QString strP = linea.mid(pos1, pos2-pos1);
            m_usuario->setPesoAct(strP.toFloat());
            ui->inPeso->setValue(strP.toFloat());
            if (mayor == 0 && menor == 0){
                mayor = strP.toFloat();
                menor = strP.toFloat();
                m_usuario->setPesoMax(strP.toFloat());
                m_usuario->setPesoMin(strP.toFloat());
            }else if (mayor < strP.toFloat()){
                mayor = strP.toFloat();
            }else if (menor > strP.toFloat()){
                menor = strP.toFloat();
            }
            pos1 = linea.indexOf('a')+2;
            pos2 = linea.indexOf('c')-1;
            QString strA = linea.mid(pos1, pos2-pos1);
            m_usuario->setAltura(strA.toFloat());
            ui->inAltura->setValue(strA.toFloat());
        }while(!entrada.atEnd());
        m_usuario->setPesoMax(mayor);
        ui->outPmax->setText(QString::number(mayor, 'f', 2));
        m_usuario->setPesoMin(menor);
        ui->outPmin->setText(QString::number(menor, 'f', 2));
    }else {
        QMessageBox::warning(this,
                             "Abrir datos",
                             "No se pudo abrir el archivo");
    }
    archivo.close();
}

Principal::~Principal()
{
    delete ui;
}

void Principal::guardar()
{
    QString nuevo = "registroIMC.txt";
    QString dirHome = QDir::home().absolutePath();
    QString nombreArchivo = dirHome + "/" + nuevo;
    QFile archivo(nombreArchivo);
    if(archivo.open(QFile::WriteOnly | QIODevice::Append)){
        QTextStream salida(&archivo);
        salida << m_fecha.day() << "/" << m_fecha.month() << "/" << m_fecha.year();
        salida << " Peso " << QString::number(m_usuario->pesoAct(), 'f', 2) << " kg";
        salida << " Altura " << QString::number(m_usuario->altura(), 'f', 2) << " cm";
        salida << "\n";
        ui->statusbar->showMessage("Calculando...", 5000);
    }else{
        QMessageBox::warning(this,
                             "Guardar datos",
                             "No se pudo guardar el archivo");
    }
    archivo.close();
}

void Principal::limpiar()
{
    ui->inPeso->setValue(0);
    ui->inAltura->setValue(0);
}

void Principal::on_cmdCalcular_clicked()
{
    m_usuario->setPesoAct(ui->inPeso->value());
    m_usuario->setAltura(ui->inAltura->value());
    m_fecha = ui->inFecha->date();
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
        guardar();
    }else{
        if (m_usuario->altura() == 0 && m_usuario->pesoAct() == 0)
            QMessageBox::warning(this,"Advertencia","El peso y la altura son cero.");
        else if (m_usuario->altura() == 0)
            QMessageBox::warning(this,"Advertencia","La altura es cero.");
        else
            QMessageBox::warning(this,"Advertencia","El peso es cero.");
    }
    limpiar();
}

