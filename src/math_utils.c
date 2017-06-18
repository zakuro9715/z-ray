double int_to_ratio(int value, int max)
{
    return value / (double)max;
}

int ratio_to_int(double value, int max)
{
    return (int)(value * max  + 0.5);
}

double clamp(double value, double min, double max)
{
    if (value < min)
    {
        return min;
    }
    if (value > max)
    {
        return max;
    }
    return value;
}
