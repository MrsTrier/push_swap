#include "push_swap.h"


void    build_max_heap(int **a)
{

}

void    heap_sort(int **a)
{
    build_max_heap(a);
  //  heapify();
}

int     *lst_to_arr(t_list *lst, int ac)
{
    t_list  *new_item;
    int     *arr;
    int     i;

    if (!lst)
        return (NULL);
    i = 0;
    new_item = lst;
    arr = (int *)malloc(sizeof(int) * ac);
    while (new_item)
    {
        arr[i] = ft_atoi(new_item->content);
        new_item = new_item->next;
        i++;
    }
    return (arr);
}

int		main(int ac, char **av)
{
    char	*line;
    t_list	*res_lst;
    t_list	*b;
    int     *stack;

    res_lst = ft_lstnew(NULL, 0);
    b = ft_lstnew(NULL, 0);
    if (!save_stack(ac, av, res_lst))
        return (0);
    stack = lst_to_arr(res_lst, ac);
    heap_sort(&stack);

}