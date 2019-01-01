/* 25. Long Pressed Name */
/* name = "alex", typed = "aaleex" */
/* name = "saeed", typed = "ssaaedd" */
class Solution
{
  public:
    bool isLongPressedName(string name, string typed)
    {
        if (typed.size() < name.size())
            return false;

        int i = 0, j = 0; 

        while(i < name.size()){
            if(name[i] != typed[j])
                return false; 
            i++; 
            j++; 
            if(i < name.size() && j < typed.size()){
                if(name[i] != name[i-1]){
                    while(j < typed.size() && typed[j] == typed[j-1]){
                        j++;
                    }
                }
            }
        }
        return true;
    }
};