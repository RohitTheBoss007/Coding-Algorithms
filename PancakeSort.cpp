//pancake sort in O(N)
//Reference https://leetcode.com/problems/pancake-sorting/discuss/494417/Dew-It-or-True-O(n)-or-Explained-with-Diagrams

class Solution {
public:
    void add(vector<int>& ans,int i){
        if(i>1){
            if(!ans.empty() and ans.back()==i) ans.pop_back();
            else ans.push_back(i);
        }
    }
    vector<int> pancakeSort(vector<int>& a) {
       
        int n=a.size();
        vector<int> ans,id(n);
        for(int i=0;i<n;i++) id[a[i]-1]=i;
                
        for(int i=0;i<n;i++){
            int p=id[i];
            //do swaps             
            if(p!=i){
                
                add(ans,p+1);
                add(ans,p-i+1);
                add(ans,p-i);
                add(ans,p-i-1);
                add(ans,p-i);               
                add(ans,p+1);
                
            }
            
           swap(a[i],a[p]);
            id[a[i]-1]=i;
            id[a[p]-1]=p;
            
            
            
        }
     
        
        return ans;
        
        
    }
};
