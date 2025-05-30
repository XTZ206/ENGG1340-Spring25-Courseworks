int gcd(int x, int y)
{
    while (x != y)
    {
        if (x > y)
        {
            x -= y;
        }
        else
        {
            y -= x;
        }
    }
    return x;
}

int lcm(int x, int y)
{
    return (x * y) / gcd(x, y);
}