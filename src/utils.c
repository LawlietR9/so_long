#include "../inc/so_long.h"

char    *concat_str(char *dst, char *s1, char *s2, char *s3)
{
    ft_strlcat(dst, s1, 64);
    ft_strlcat(dst, s2, 64);
    ft_strlcat(dst, s3, 64);
    return (dst);
}

char *ft_snprintf(char *dst, const char *format, ...)
{
    va_list ap;
    va_start(ap, format);
    vsnprintf(dst, 64, format, ap);
    va_end(ap);
    return (dst);
}