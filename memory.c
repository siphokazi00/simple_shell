/**
 * bfree - Frees memory associated with a pointer and sets it to NULL.
 * @ptr: Address of the pointer to be freed and NULLed.
 *
 * Returns: 1 if memory was freed, 0 if no action was taken.
 */
int bfree(void **ptr)
{
    if (ptr && *ptr)
    {
        free(*ptr);
        *ptr = NULL;
        return 1;
    }
    return 0;
}
