#include "DisjointSets.h"

/**
 * Construct the disjoint sets object.
 * numElements is the initial number of disjoint sets.
 */
DisjointSets::DisjointSets(const int numElements) : s(numElements, -1)
{
}

/**
 * Union two disjoint sets.
 */
void DisjointSets::unionSets(const int root1, const int root2)
{
   s[root2] = root1;
}

/**
 * Perform a find (does not change anything).
 * Return the set containing x.
 */
int DisjointSets::find(const int x) const
{
   if(s[x] < 0)
   {
     return x;
   }
 return find(s[x]);
}


/**
 * Perform a find with path compression (the mutator version).
 * Return the set containing x.
 */
int DisjointSets::find(const int x)
{
  if(s[x] < 0)
  {
    return x;
  }
	  s[x] = find(s[x]);
	  return s[x];
}
