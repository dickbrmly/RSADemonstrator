//*************************************************************************************************

//*************************************************************************************************
long long int modulus(long long int numerator, long long int key, long long int denominator )
{
    long long int temp = 1;
    while (key > 1)
    {
        temp = (temp * numerator * numerator) - denominator * ((temp * numerator * numerator) / denominator);
        key -= 2;
    }
   if(key > 0)  temp = temp * numerator - denominator*( (temp * numerator) / denominator);
    return temp;
}
//*************************************************************************************************

//*************************************************************************************************
long long int ExtendedEuclidian(long long int totient, long long int pubkey)
{
    long long int n = totient;
    long long int e = pubkey;
    long long int temp;
    long long int q = 1;
    long long int privkey = totient;

    while(e != 1)
    {
         privkey = privkey -q * (n / e);
        while (privkey < 1) privkey = privkey + totient;
        if (e == 1) break;
        temp = q;
        q = privkey;
        privkey = temp;
        temp = n - e* (n / e);
        n = e;
        e = temp;
    }
    return q;
}
//*************************************************************************************************

//*************************************************************************************************
bool primeTest(long long int  number)
{
    long long  int base []  = {3, 7, 11, 13, 17, 19, 23, 29}; //can be increased
    int size = 8; // size of base array
    long long int exp = number - 1;
    long long int temp;
    long long int  test = 0;
    int state = 0;

    if (number < 4) return true;
    for (int x = 0; x < size; x++)  if ( number == base[x] ) return true;
    else if (number % 2 == 0) return false;

    while ((int)exp % 2 == 0) exp = exp / 2;
    if (exp < 3) exp = 3;
    temp = exp;

    for ( int x = 0; x < size; x++)
    {
        state = 0;
        exp = temp;
        while ( exp < number)
        {
            test = modulus(base[0], exp, number);
           if ( test == 1 ||  test == ( number - 1)) state++;
           if (state == 2) break;
           exp = exp * 2;
        }
        if (state != 2) return false;
    }
    return true;
}
//*************************************************************************************************

//*************************************************************************************************
