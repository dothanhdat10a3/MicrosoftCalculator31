#include "number.h"

Number::Number(QObject *parent) : QObject(parent)
{

}

Number::~Number()
{

}

int Number::getNumber()
{
    return m_number;
}

int Number::castNumberFromHexToDec(string numberInput)
{
    int base = 16;
    for(int i = numberInput.length() - 1, j = 0; i >= 0; i--, j++){
        m_decValue += (numberInput[j]-48)*(pow(base,i));
    }
    qDebug ("Dm_decValue: %d", m_decValue);
    return m_decValue;
}

int Number::castNumberFromDecToDec(string numberInput)
{
    int base = 10;
    for(int i = numberInput.length() - 1, j = 0; i >= 0; i--, j++){
        m_decValue += (numberInput[j]-48)*(pow(base,i));
    }

    qDebug ("m_decValue:%d", m_decValue);
    return m_decValue;
}

int Number::castNumberFromOctToDec(string numberInput)
{
    int base = 8;
    for(int i = numberInput.length() - 1, j = 0; i >= 0; i--, j++){
        m_decValue += (numberInput[j]-48)*(pow(base,i));
    }

    qDebug ("%d", m_decValue);
    return m_decValue;
}

int Number::castNumberFromBinToDec(string numberInput)
{
    int base = 2;
    for(int i = numberInput.length() - 1, j = 0; i >= 0; i--, j++){
        m_decValue += (numberInput[j]-48)*(pow(base,i));
    }

    qDebug ("%d", m_decValue);
    return m_decValue;
}

int* Number::castFromDecToHex(int number)
{
    while(number > 0){
        m_hexNumber[indexHex] = number % 16;
        number = number / 16;
        indexHex++;
        qDebug("indexHex: %d",indexHex);
    }
    for(int i = indexHex - 1, j = 0; i >= 0; i--, j++)
    {
        m_hexNumberToShow[j] = m_hexNumber[i];
    }
    return m_hexNumberToShow;
}

int* Number::castFromDecToDec(int number)
{
    while(number > 0){
        m_decNumber[index] = number % 10;
        qDebug("Dat: %d",number % 10);
        number = number / 10;
        index++;
    }
    int i,j;
    for(i = index - 1, j = 0; i >= 0; i--, j++)
    {
        qDebug("D : %d", index);
        m_decNumberToShow[j] = m_decNumber[i];

    }
    index = 0;
    return m_decNumberToShow;
}

int* Number::castFromDecToOct(int number)
{
    while(number > 0){
        m_octNumber[index] = number % 8;
        number = number / 8;
        index++;
    }
    for(int i = index - 1, j = 0; i >= 0; i--, j++)
    {
        m_octNumberToShow[j] = m_octNumber[i];
    }
    index = 0;
    return m_octNumberToShow;
}

int* Number::castFromDecToBin(int number)
{
    while(number > 0){
        m_binNumber[index] = number % 2;
        number = number / 2;
        index++;
    }
    for(int i = index - 1, j = 0; i >= 0; i--, j++)
    {
        m_binNumberToShow[j] = m_binNumber[i];
    }
    index = 0;
    return m_binNumberToShow;
}

int *Number::getHexNumberToShow()
{
    return m_hexNumberToShow;
}

int *Number::getDecNumberToShow()
{
    return m_decNumberToShow;
}

int *Number::getOctNumberToShow()
{
    return m_octNumberToShow;
}

int *Number::getBinNumberToShow()
{
    return m_binNumberToShow;
}

int Number::getIndexHex()
{
    return indexHex;
}

void Number::castToDecimal(RADIX_TYPE radixType)
{
    switch (radixType) {
    case HEX_RADIX_TYPE:
        m_number = castNumberFromHexToDec(m_numberInput);
        qDebug("m_number : %d", m_number);
        break;
    case DEC_RADIX_TYPE:
        m_number = castNumberFromDecToDec(m_numberInput);
        break;
    case OCT_RADIX_TYPE:
        m_number = castNumberFromOctToDec(m_numberInput);
        break;
    case BIN_RADIX_TYPE:
        m_number = castNumberFromBinToDec(m_numberInput);
        break;
    default:
        break;
    }
}

void Number::setNumber()
{
    castFromDecToHex(m_number);
    castFromDecToDec(m_number);
    castFromDecToOct(m_number);
    castFromDecToBin(m_number);
}



