#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "dico.h"

int	main()
{
  noeud *root;
 
  root = initialiser();
  add_word(root,"magneti");
  add_word(root,"magneton");
  add_word(root,"smogo");
  add_word(root,"smogogo");
  add_word(root,"nidoran");
  add_word(root,"nidorina");
  add_word(root,"nidoqueen");
  add_word(root,"nidoking");
  aff_noeud(root);
  suppr_word(root,"trololo");
  suppr_word(root,"nidorina");
  suppr_word(root,"magneti");
  aff_noeud(root);
 

  return (EXIT_SUCCESS);
}
