class FizzBuzz {
private:
    int n;
    int f,b,fb,o;
    condition_variable fizz1;
    condition_variable buzz1;
    condition_variable fizzbuzz1;
    condition_variable other1;
    mutex m;
public:
    FizzBuzz(int n) {
        this->n = n;
        this->f=0;
        this->b=0;
        this->fb=0;
        this->o=1;
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        for(int i=3;i<=n;i+=3)
        {  
            if(i%5!=0)
            {
                unique_lock<mutex> ul(m);
                fizz1.wait(ul,[this](){return f>0;});
                printFizz();
                o=1;
                f=0;
                other1.notify_one();
            }   
        } 
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        for(int i=5;i<=n;i+=5)
        {
            if(i%3!=0)
            {
                unique_lock<mutex> ul(m);
                buzz1.wait(ul,[this](){return b>0;});
                printBuzz();
                o=1;
                b=0;
                other1.notify_one();
            }
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(function<void()> printFizzBuzz) {
        for(int i=15;i<=n;i+=15)
        {
            unique_lock<mutex> ul(m);
            fizzbuzz1.wait(ul,[this](){return fb>0;});
            printFizzBuzz();
            o=1;
            fb=0;
            other1.notify_one();
        } 
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        for(int i=1;i<=n;i++)
        {
            unique_lock<mutex> ul(m);
            other1.wait(ul,[this](){return o>0;});
            if(i%3!=0 && i%5!=0)
            {
                printNumber(i);
            }
            else if(i%3==0 && i%5==0)
            {
                fb=1;
                o=0;
                fizzbuzz1.notify_one();
            }
            else if(i%3==0)
            {
                f=1;
                o=0;
                fizz1.notify_one();
            }
            else if(i%5==0)
            {
                b=1;
                o=0;
                buzz1.notify_one();
            }
        }
    }
};