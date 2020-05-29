#ifndef SKILLSANDINIT_H_INCLUDED
#define SKILLSANDINIT_H_INCLUDED

//1.1.1 C++ÅÅÐòÐÔÄÜ sort functor> qsort >sort function
/**bool myfunction (int i,int j) { return (i<j); }
   struct myclass {
         bool operator() (int i,int j) { return (i<j);}
    } myobject;
    int cmp4qsort(const void* a,const void* b){
        return (*(int*)a - *(int*)b)
    }

  int myints[] = {32,71,12,45,26,80,53,33};
  std::vector<int> myvector (myints, myints+8);
  qsort(myhints, 8, sizeof(int), cmp4qsort);
  std::sort (myvector.begin(), myvector.end());
  std::sort (myvector.begin(), myvector.end(), myfunction);
  std::sort (myvector.begin(), myvector.end(), myobject);
*/
//1.1.2


#endif // SKILLSANDINIT_H_INCLUDED
