double calculator(char c,double a,double b)
{
    switch(c)
    {
        case '+':
            return a+b;
            break;
        case '-':
            return a-b;
            break;
        case '*':
            return a*b;
            break;
        case '/':
            return (double)a/b;
            break;
    }
}

void Itorevs(int n,char*str)
{
    memset(str,'0',MAX);
    for(int pos=0;n>0;pos++)
    {
        str[pos]='0'+n%10;
        n/=10;
    }
}

void LargeMultiply(char*a,char*b,char*res)
{
    memset(res,'0',MAX);
    int alen,blen;
    for(alen=MAX-1;a[alen]=='0';alen--)
        ;
    for(blen=MAX-1;b[blen]=='0';blen--)
        ;
    int c=0;
    for(int i=0;i<=alen+1;i++)
    {
        for(int j=0;j<=blen+1;j++)
        {
            c+=(a[i]-'0')*(b[j]-'0');
            res[i+j]+=c%10;
            if(res[i+j]>'9')
            {
                res[i+j]-=10;
                res[i+j+1]++;
            }
            c=c/10;
        }
    }
}

void Largesum(char*a,char*b,char*res)
{
    memset(res,'0',MAX);
    int alen,blen,i;
    for(alen=MAX-1;a[alen]=='0';alen--)
        ;
    for(blen=MAX-1;b[blen]=='0';blen--)
        ;
    int c=0;
    for(i=0;i<=alen||i<=blen;i++)
    {
        c+=a[i]+b[i]-'0'-'0';
        res[i]=c%10+'0';
        c=c/10;
    }
    if(c!=0) res[i]='0'+c;
}

int Digits(int n)
{
    int dig=0;
    for(;n>0;dig++)
    {
        n=n/10;
    }
    return dig;
}

int IsPrime(int t)
{
    if(t==1) return 0;
    int u;
    for(u=2;u*u<=t;u++)
    {
        if(t%u==0)return 0;
    }
    return 1;
}

int IsPalindrome(char*s)
{
	int len;
	for(len=MAX-1;s[len]=='0';len--)
        ;
	for(int pos=0;pos<=len/2;pos++)
    {
        if(s[pos]!=s[len-pos]) return 0;
    }
    return 1;
}

int Ord(int p,int n)
{
    int t;
    for(t=0;n%p==0;t++)
    {
        n=n/p;
    }
    return t;
}

int Reverse(int n)
{
    int len,rev=0,i,k,ncopy,temp;
    ncopy=n;
    for(len=0;ncopy>0;len++)
        ncopy/=10;
    for(i=1;i<=len;i++)
    {
        temp=1;
        for(k=1;k<=len-i;k++) temp*=10;
        rev+=(n%10)*temp;
        n/=10;
    }
    return (int)rev;
}

void Reverse(char*a,char*res)
{
    memset(res,'0',MAX);
	int len,i;
    for(len=MAX-1;a[len]=='0';len--)
        ;
    for(i=len;i>=0;i--)
    {
    	res[len-i]=a[i];
	}
}

int Digpowersum(int n,int power)
{
    int dig,psum=0,pow;
    for(;n>0;)
    {
        dig=n%10;
        pow=dig;
        for(int t=2;t<=power;t++)
        {
            pow*=dig;
        }
        psum+=pow;
        n=n/10;
    }
    return psum;
}

void PrimeFactorization(int i)
{
    int p,times=0,first=0;
    for(p=2;i!=1;)
    {
        if(i%p==0)
        {
            i=i/p;
            times++;
        }
        else
        {
            if(times>1)
            {
               if(first==0) {printf("%d^%d",p,times); first=1;}
               else printf("*%d^%d",p,times);
            }
            else if(times==1)
            {
                if(first==0) {printf("%d",p); first=1;}
               else printf("*%d",p);
            }
            p++;
            times=0;
        }
    }
   if(times>1)
    {
        if(first==0) {printf("%d^%d",p,times); first=1;}
        else printf("*%d^%d",p,times);
    }
    else if(times==1)
    {
        if(first==0) {printf("%d",p); first=1;}
        else printf("*%d",p);
    }
}

int MaxCommonDivisor(int m,int n)
{
    int t;
    if(n>m)
    {
        t=n;
        n=m;
        m=t;
    }
    if(m%n==0) return n;
    else return MaxCommonDivisor(n,m%n);
}

int CountDivisor(int n)
{
    int i,c=0;
    for(i=1;i*i<=n;i++)
    {
       if(n%i==0) c++;
    }
    if((i-1)*(i-1)==n)
        return 2*c-1;
    else
        return 2*c;
}

int SumofDivisors(int n)
{
    int i,s=1;
    for(i=2;i*i<n;i++)
    {
       if(n%i==0) s+=i+n/i;
    }
    if(i*i==n)
        return s+i;
    else
        return s;
}

int Fibonacci(int n)
{
    if(n==1||n==2)
        return n;
    else
        return Fibonacci(n-1)+Fibonacci(n-2);
}

int C(int m,int n)
{
    int re=1,i;
    for(i=1;i<=n;i++)
    {
        re*=m+1-i;
    }
    for(i=1;i<=n;i++)
    {
        re/=i;
    }
    return re;
}

int A(int m,int n)
{
    int re=1,i;
    for(i=1;i<=n;i++)
    {
        re*=m+1-i;
    }
    return re;
}

int Category(int m,int n)
{
    if(m<0) return 0;
    else if(m==0) return 1;
    else if(n==1)return 1;
    else return Category(m,n-1)+ Category(m-n,n);
}

int Wordlen(const char*p)
{
    int len;
    for(len=0;(p[len]>='A'&&p[len]<='Z')||(p[len]>='a'&&p[len]<='z');len++);
    return len;
}

int IsLetter(char n)
{
    if((n<='Z'&&n>='A')||(n<='z'&&n>='a')) return 1;
    else return 0;
}

int IsNumber(char n)
{
    if(n<='9'&&n>='0') return 1;
    else return 0;
}

void Capitalize(char*s)
{
    int i;
    for(i=0;s[i]!='\0';i++)
    {
        if(s[i]<='z'&&s[i]>='a') s[i]=s[i]-'a'+'A';
    }
}

int Daysofyear(int year)
{
    if(year%4!=0) return 365;
    else if(year%100==0&&year%400!=0) return 365;
    else return 366;
}

int Daysofmonth(int month, int year)
{
    if(month==1||month==3||month==5||month==7||month==8||month==10||month==12) return 31;
    else if(month!=2) return 30;
    else if((year%4==0&&year%100!=0)||(year%400==0)) return 29;
    else return 28;
}

int Daysbetween(int styr,int edyr,int stmn,int edmn,int stdy,int eddy)
{
    int s=0,i;
    for(i=styr;i<edyr;i++)
    {
        s+=Daysofyear(i);
    }
    for(i=1;i<stmn;i++)
    {
        s-=Daysofmonth(i,styr);
    }
    for(i=1;i<edmn;i++)
    {
        s+=Daysofmonth(i,edyr);
    }
    s=s-stdy+eddy;
    return s;
}

int Qsortdown(const void*p1,const void*p2)
{
    return(*(int*)p2-*(int*)p1);
}

int Qsortup(const void*p1,const void*p2)
{
    return(*(int*)p1-*(int*)p2);
}
