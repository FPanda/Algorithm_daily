typedef struct DequeNode
{
    DequeNode(void):val(0),next(-1),pre(-1){return;}
    int val;
    int next;
    int pre;
}DequeNode;

class MyCircularDeque {
public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) {
        m_deqCapacity = k;
        m_deqSize = 0;
        indexStart = -1;
        indexRear = -1;
        pArray = new DequeNode[k];
    }
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if(!capacityCheck())
        {
            return false;
        }
        m_deqSize++;
        for(auto i = 0; i < m_deqCapacity;i++)
        {
            if(pArray[i].next == -1 && pArray[i].pre == -1)
            {
                pArray[i].val = value;

                if(indexStart!=-1)
                {
                    pArray[indexStart].pre = i;
                    pArray[i].next = indexStart;
                }
                else
                {
                    pArray[i].next = i;
                }

                indexStart = i;

                if(indexRear == -1)
                {
                    indexRear = indexStart;
                }

                break;
            }
        }
        return true;
    }
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if(!capacityCheck())
        {
            return false;
        }
        m_deqSize++;
        for(auto i = 0; i < m_deqCapacity;i++)
        {
            if(pArray[i].next == -1 && pArray[i].pre == -1)
            {
                pArray[i].val = value;

                if(indexRear!=-1)
                {
                    pArray[indexRear].next = i;
                    pArray[i].pre = indexRear;
                }
                else
                {
                    pArray[i].pre = i;
                }

                indexRear = i;

                if(indexStart == -1)
                {
                    indexStart = indexRear;
                }
                
                break;
            }
        }
        return true;
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if(m_deqSize==0)
        {
            return false;
        }

        int newStart = pArray[indexStart].next;
        
        pArray[indexStart].pre = -1;
        pArray[indexStart].next = -1;

        if(--m_deqSize == 0)
        {
            indexStart = -1;
            indexRear = -1;
        }
        else
        {
            indexStart = newStart;
        }

        return true;
    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if(m_deqSize==0)
        {
            return false;
        }

        int newRear = pArray[indexRear].pre;
        
        pArray[indexRear].pre = -1;
        pArray[indexRear].next = -1;

        if(--m_deqSize == 0)
        {
            indexStart = -1;
            indexRear = -1;
        }
        else
        {
            indexRear = newRear;
        }
        
        return true;
    }
    
    /** Get the front item from the deque. */
    int getFront() {
        if(m_deqSize ==0) return -1;

        return pArray[indexStart].val;
    }
    
    /** Get the last item from the deque. */
    int getRear() {
        if(m_deqSize ==0) return -1;

        return pArray[indexRear].val;
    }
    
    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return ((m_deqSize==0)?true:false);
    }
    
    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        return ((m_deqSize==m_deqCapacity)?true:false);
    }
private:
    inline bool capacityCheck(void)
    {
        return ((m_deqCapacity == m_deqSize)?false:true);
    }

    int m_deqCapacity;
    int m_deqSize;
    DequeNode* pArray;
    int indexStart;
    int indexRear; 
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
