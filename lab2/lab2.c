int gLast;
long long func(long long i)
{
    gLast = i;
    if(i >= 12345678)
    {
        i /= 1000;
    }
    return i;
}
