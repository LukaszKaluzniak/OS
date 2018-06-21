void p_error(const char *str)
{
  fprintf(stderr, "%s: %s\n", str, strerror(errno));
  return;
}
