class MedianFinder {
private:
    priority_queue<int> leftHeap; //max heap
    priority_queue<int, vector<int>, greater<int>> rightHeap; //min heap

public:
    MedianFinder() {
        
    }
    

    void addNum(int num) {
        if(leftHeap.empty()){
            leftHeap.push(num);
        }else{
            if(leftHeap.size() > rightHeap.size()){
                if(num > leftHeap.top()){
                    rightHeap.push(num);
                }else{
                    leftHeap.push(num);
                    rightHeap.push(leftHeap.top());
                    leftHeap.pop();
                }
            }else if(leftHeap.size() == rightHeap.size()){
                if(num < leftHeap.top()){
                    leftHeap.push(num);
                }else{
                    rightHeap.push(num);
                    leftHeap.push(rightHeap.top());
                    rightHeap.pop();
                }
            }else{
                cout<<"error"<<endl;
            }
        }
    }
    
    double findMedian() {
        if(leftHeap.size() == rightHeap.size()){
            double res = ((double)leftHeap.top()+(double)rightHeap.top())/2;
            return res;
        }
        return leftHeap.top();
    }
};

//addNum ()
//Time Complexity: O(logN)
//Space Complexity: O(N)
//findMedian ()
//Time Complexity: O(1)
//Space Complexity: O(1)
