#ifndef USUARIO_H
#define USUARIO_H

#include <QObject>
#include <math.h>

class Usuario : public QObject
{
    Q_OBJECT
public:
    explicit Usuario(QObject *parent = nullptr);

    bool calcularIMC();

    float pesoAct() const;
    void setPesoAct(float newPesoAct);
    float pesoMax() const;
    void setPesoMax(float newPesoMax);
    float pesoMin() const;
    void setPesoMin(float newPesoMin);
    float altura() const;
    void setAltura(float newAltura);
    float imc() const;
    void setImc(float newImc);

signals:

private:
    float m_pesoAct;
    float m_pesoMax;
    float m_pesoMin;
    float m_altura;
    float m_imc;
};

#endif // USUARIO_H
