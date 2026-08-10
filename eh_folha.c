int ehFolha(Tarv *a)
{
    if (a != NULL)
    {
        if ((a->esq == NULL) && (a->dir == NULL))
        {
            return 1;
        }

        return 0;
    }
}
