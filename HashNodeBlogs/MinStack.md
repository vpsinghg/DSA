## Min Stack - Interview Bit Solution, Problem is based on Stack Data Structure

Hi Devs, Happy Coding

Today, I will be solving a problem titled [Min Stack](https://www.interviewbit.com/problems/min-stack/) which is based on Stack Data Structure.

**Difficulty Level** - Medium
**Asked In:**
- YAHOO
- AMAZON
- ADOBE
- MICROSOFT
- GRAB
- TWITTER

#### **Understanding The Problem**

**Problem Description**

> Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
1. push(x) – Push element `x` onto the stack.
2. pop() – Removes the element on top of the stack.
3. top() – Get the top element.
4. getMin() – Retrieve the minimum element in the stack.

**Problem Note**
All the operations above mentioned have to be constant time (`O(1)`) operations.

As we read the problem description we are not clear about a few cases. So we should ask the Interviewer about those cases.

**Here we can ask the following questions**
Q: What should getMin() do on an empty stack? 
A: In this case, return -1.

Q: What should pop do on an empty stack? 
A: In this case, nothing. 

Q: What should top() do on an empty stack?
A: In this case, return -1

**Example** 

```
Consider the following stack that we want
4  --> TOP
2
5
3

When getMin() is called it should return 2, 
which is the minimum element in the current stack. 

If we do pop two times on stack, the stack becomes
5  --> TOP
3
When getMin() is called, it should return 3
which is the minimum in the current stack.
```
**Solutions**

1. **Brute Force Solution** - We can use two stack one for storing out main stack `main_stack` and other auxiliary stack for storing `min_value`. Our push and pop operations should be in such a way that minimum value in stack should be always at the top of `min_stack`.
2. We will try to optimise the space complexity using single stack.

**Brute Force Solution** - 
We have two stack `main_stack` and `min_stack` as discussed above. Our push, pop, getMin and top operations will be following .
**push(x)** - we will directly push the `x` in `main_stack` `main_stack.push(x)`. our new minimum_value will be `new_min = min(x, min_stack.top())` so now push the `new_min` in `min_stack` `min_stack.push(new_min)`. Both push are **C++ standard template library methods in stack container** and we know both have `O(1)` time complexity. So overall push will be also of `O(1)` time complexity.

**Pop()** - if stack is empty then do nothing. else pop the top element from `main_stack` as well as `min_stack`. Both pop methods are from **c++ stl** and both have `O(1)` time complexity so overall complexity will be of `O(1)` as well.

**top()** - if `main_stack` is empty then return -1 else return `main_stack.top()`. top method also has time complexity of `O(1)`.

**getMin()**- if `min_stack` is empty then return -1 else return `min_stack.top()`. This top will also have time complexity of `O(1)`.

**Explanation with Our Example**

```
When we push 3, both stacks change to the following.
Main Stack             Min Stack
3 -> Top               3->Top

When 5 is pushed, both stacks change to the following.
Main Stack             Min Stack
4 -> Top               3->Top
3                          3

if we apply the top method then it will return 4 which is the correct solution.

if we apply the getMin method then the top of the Min stack will be returned which is 3.

if we apply the pop method then we will pop 4 from the main stack and two update min stack we will also pop 3 so new stacks will be
Main Stack             Min Stack
3 -> Top               3->Top
```
**Brute Force Solution Complexity Analysis**

- Time Complexity- we have `O(1)` time complexity for all push, pop, top and getMin methods.
- Space Complexity - we are using the extra auxiliary stack for storing minimum value. Our space complexity is `O(n)`.

## Optimised Solution
In this approach, we will be solving the problem in `0(1)` space complexity. Instead of storing min values in the stack, we will try to use a single value variable Min_value which will store the current minimum value in the stack. 
In this approach critical part will be when we pop a value and that value is itself current `Min_value` then How to get the next `Min_value`?

**How we are going handle this ?**
To handle this, we push `2*x – Min_value` into the stack instead of `x` so that the previous minimum element can be retrieved using the current `Min_value` and its value stored in the stack.
So Our operations push, pop,getMin, and top are implemented as follows.

**Push(x)** 
- If stack is empty, insert `x` into the stack and make Min_value equal to `x`.
- if `x` is less than Min_value then insert `(2*x- Min_value)` into stack and update `Min_value` equal to `x`.
- if `x>=Min_value` then insert `x` into stack.
Example: let's assume we have minimum value in stack till now as 3 and now want to insert 1 then we will insert `(2*1 -3)` in the stack and make `Min_value = 1`.

**Pop ()** 
pop the top element and Let the popped element be y then our critical case might occur. 
- if `y>=Min_value` then our Min_value will remain Min_Value. Because the popped element is not less than Min_Value.
- But if `y< Min_value` then it is the case when we are removing the current minimum element of the stack. So we need to find out the next Min_value. and `Min_value = 2*y - Min_value`.  

> Can anyone guess why we used `Min_value  =2*y -Min_value`? Write in Comment Section (Writer’s 1st Question to you)

**Top()** 

- if stack is empty return -1. 
- Let `z = stack.top()`, If `z>= Min_value` then return z. It will be original top.
- If `z<Min_value` then return Min_value . `Anyone Want to guess ? Let me know in comment Section `(Writer’s 2nd Question).

**getMin**- if the stack is empty then return -1 else It is simply the Min_value.
 

## Complete Code

```
stack<int> s;
int mini;
MinStack::MinStack() {
    s = stack<int>();
}

void MinStack::push(int x) {
    if(s.empty()){
        mini = x;
    }
    if(x>=mini){
        s.push(x);
    }
    else{
        s.push(2*x-mini);
        mini = x;
    }
}

void MinStack::pop() {
    if(s.empty()){
        return;
    }
    if(s.top()<mini){
        mini = 2*mini - s.top();
    }
    s.pop();
}

int MinStack::top() {
    if(s.empty()) {
        return -1;
    }
    

    if(s.top() >=mini){
        return s.top();
    }
    else{
        return mini;
    }
}

int MinStack::getMin() {
    if(s.empty()){
        return -1;
    }
    return mini;
}

```

**Answer to Questions that I asked and  Why our logic works.**
When the element to be inserted is less than Min_value, we inserted `2x – Min_value`. The important thing to note here is that `2x – Min_Value` will always be less than x(which will become the next Min_value) Because

```
How 2*x - Min_value is less than x in push()? 
x < Min_value which means x - Min_value < 0

// Adding x on both sides
x - Min_value + x < 0 + x 

2*x - Min_value < x 

So we can say that 2*x - Min_value < new Min_value 
```
So when we pop out elements and we get a top value less than Min_value then It is clear that We are popping out Min_value. So we need to update our Min_value. How it is calculated is explained below.

```
How previous minimum element, prev_Min_Value is 2*minEle - y
in pop() when y the popped element?
because when we pushed y =(2*x-prev_Min_Value) here prev_Min_Value is the minimum element before we inserted y. and here x is an original value that we received to insert.
and after insert, we set Min_value = x.
So 
our equation will be y = 2*Min_Value - prev_Min_Value 
which leads us to get prev_Min_Value as 2*Min_value - y (y is the value we just popped out)
```

Hope you find it Relevant. If you face any issues while understanding and have any feedback then the comment box is all yours. Cheers