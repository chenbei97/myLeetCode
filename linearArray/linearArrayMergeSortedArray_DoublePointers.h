#ifndef linearArrayMergeSortedArrayDoublePointers_
#define linearArrayMergeSortedArrayDoublePointers_
class linearArrayMergeSortedArrayDoublePointers{
    public:
        void mergeSortedArray(vector<int>&nums1,vector<int>&nums2){
            int n1=nums1.size()-1,n2=nums2.size()-1;
            sort(nums1.begin(),nums1.end()); //先排序
            sort(nums2.begin(),nums2.end());
            int p1=0,p2=0; // 2个指针
            vector<int> *ans = new vector<int>(); // 必须new否则会出错
            while (p1<=n1||p2<=n2){
                if (nums1[p1]<=nums2[p2]){
                    ans->push_back(nums1[p1]); // 小的指针++
                    p1++;
                }
                else{
                    ans->push_back(nums2[p2]);
                    p2++;
                }
                if (p1>n1 && p2<=n2){ // 如果有1个指针先到达,就直接把另一个剩余元素直接push退出
                    for(int i=p2;i<=n2;i++)
                        ans->push_back(nums2[i]);
                    break;
                }
                if (p2>n2 && p1<=n1){ // 不会存在2个指针同时都大于位置n1和n2
                    for(int i = p1; i<=n1;i++)
                        ans->push_back(nums1[i]);
                    break;
                }
            }
            nums1.clear();
            nums1 = *ans;
        }
};
void _linearArray_mergeSortedArray_doublePointers(){
    linearArrayMergeSortedArrayDoublePointers solution;
    cout<<"doublePointers:\n";
    vector<int> v1 ={15,4,3,2};
    vector<int> v2 = {3,1,7,0};
    solution.mergeSortedArray(v1,v2);
    for(int i =0;i<v1.size();i++)
        cout<<v1[i]<<" ";
    cout<<"\n";
}
#endif // !linearArrayMergeSortedArrayDoublePointers_