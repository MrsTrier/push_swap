

void    build_max_heap(int **a, int i, int max)
{
    int big_i;
    int chld_l;
    int chld_r;
    int tmp;

    while (i < max)
    {
        big_i = i;
        chld_l = 2 * i + 1;
        chld_r = 2 * i + 2;
        if (chld_l < max && *(*a + chld_l) > *(*a + big_i))
            big_i = chld_l;
        if (chld_r < max && *(*a + chld_r) > *(*a + big_i))
            big_i = chld_r;
        if (big_i == i)
            return;
        tmp = *(*a + i);
        *(*a + i) = *(*a + big_i);
        *(*a + big_i) = tmp;
        i = big_i;
    }
}

void    heapify(int max, int **stack)
{
    int tmp;

    while (max >= 0)
    {
        tmp = *(*stack + 0);
        *(*stack + 0) = *(*stack + max);
        *(*stack + max) = tmp;
        build_max_heap(stack, 0, max);
        max--;
    }
}

void    heap_sort(int max, int **stack)
{
    int     i;

    i = (max / 2) - 1;
    while (i >= 0)
    {
        build_max_heap(stack, i, max);
        i--;
    }
    heapify(max - 1, stack);
}