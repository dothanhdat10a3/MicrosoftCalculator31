#ifndef NUMBER_H
#define NUMBER_H
#include <QObject>
#include <QDebug>

#include <iostream>
#include <math.h>
using namespace std;

enum RADIX_TYPE{
    HEX_RADIX_TYPE = 0,
    DEC_RADIX_TYPE,
    OCT_RADIX_TYPE,
    BIN_RADIX_TYPE
};

class Number : public QObject
{
    Q_OBJECT
public:
    explicit Number(QObject *parent = nullptr);
    ~Number();

public:
    int getNumber();
    void setNumber();
    void castToDecimal(RADIX_TYPE radixType);

    //cast number to Decimal
    int castNumberFromHexToDec(string numberInput);
    int castNumberFromDecToDec(string numberInput);
    int castNumberFromOctToDec(string numberInput);
    int castNumberFromBinToDec(string numberInput);

    // convert Radix from Dec
    int* castFromDecToHex(int number);
    int* castFromDecToDec(int number);
    int* castFromDecToOct(int number);
    int* castFromDecToBin(int number);

    //getter
    int* getHexNumberToShow();
    int* getDecNumberToShow();
    int* getOctNumberToShow();
    int* getBinNumberToShow();

    int getIndexHex();
private:
    int index = 0;
    int indexHex = 0;
    int indexDec = 0;
    int indexOct = 0;
    int indexBin = 0;

    int m_decValue;
    int m_number;
    string m_numberInput = "68";

    int m_hexNumber[100] = {0};
    int m_decNumber[100] = {0};
    int m_octNumber[100] = {0};
    int m_binNumber[64] = {0};

    int m_hexNumberToShow[100] = {0};
    int m_decNumberToShow[100] = {0};
    int m_octNumberToShow[100] = {0};
    int m_binNumberToShow[64] = {0};

};


#endif // NUMBER_H
