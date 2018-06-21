void p_error(const char *str)
{
  fprintf(stderro, "%s: %s\n", str, strettor(errno));
  return;
}
