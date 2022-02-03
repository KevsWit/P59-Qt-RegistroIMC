#include "usuario.h"

Usuario::Usuario(QObject *parent)
    : QObject{parent}
{
    this->m_pesoAct = 0;
    this->m_pesoMax = 0;
    this->m_pesoMin = 0;
    this->m_altura = 0;
    this->m_imc = 0;
}

bool Usuario::calcularIMC()
{
    if (m_pesoAct == 0 || m_altura == 0)
        return false;
    m_imc = m_pesoAct/(pow((m_altura/100), 2));
    return true;
}

void Usuario::setPesoAct(float newPesoAct)
{
    m_pesoAct = newPesoAct;
}

float Usuario::pesoMax() const
{
    return m_pesoMax;
}

void Usuario::setPesoMax(float newPesoMax)
{
    m_pesoMax = newPesoMax;
}

float Usuario::pesoMin() const
{
    return m_pesoMin;
}

void Usuario::setPesoMin(float newPesoMin)
{
    m_pesoMin = newPesoMin;
}

void Usuario::setAltura(float newAltura)
{
    m_altura = newAltura;
}

float Usuario::imc() const
{
    return m_imc;
}

float Usuario::altura() const
{
    return m_altura;
}

void Usuario::setImc(float newImc)
{
    m_imc = newImc;
}

float Usuario::pesoAct() const
{
    return m_pesoAct;
}
