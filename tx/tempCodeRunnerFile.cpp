string func1(string& str,int k) {
//     vector<string> heap;
//     int len = str.size();
//     for(int i=0;i<len;i++) {
//         string tmp = str.substr(i,len-i);
//         if(heap.size()<k) heap.push_back(tmp);
//         else if(!find(heap,tmp)) {
//             make_heap(heap,heap.begin(),heap.end(),greater<string>());

//         }
//     }    
//     return ret;
// }