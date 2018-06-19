class Box
{
    private:
    int length;
    int height;
    int breadth;
    public:
    Box(): length(0),height(0),breadth(0){}
    Box(const int l, const int h, const int b): length(l),height(h),breadth(b){}
    Box(const Box& b) = default;
    int getLength() const
    {
        return length;
    }
    int getHeight() const
    {
        return height;
    }
    int getBreadth() const
    {
        return breadth;
    }
    long long CalculateVolume() const
    {
        return (long long)length *(long long)height *(long long)breadth;
    }
    friend bool operator < (Box& a, Box& b) 
    {
        bool value = false;
        if (a.length < b.length)
        {
            value = true;
        }
        else if((a.breadth < b.breadth) && (a.length == b.length))
        {
            value = true;
        }
        else if((a.height < b.height) && (a.breadth == b.breadth) && (a.length == b.length))
        {
            value = true;
        } 
        return value;
    }
    friend ostream& operator << (ostream& out, Box& b)
    {
        out << b.length << " " << b.height << " " << b.breadth; 
        return out;
    }
};

void check2()
{
    int n;
    cin>>n;
    Box temp;
    for(int i=0;i<n;i++)
    {
        int type;
        cin>>type;
        if(type ==1)
        {
            cout<<temp<<endl;
        }
        if(type == 2)
        {
            int l,b,h;
            cin>>l>>b>>h;
            Box NewBox(l,b,h);
            temp=NewBox;
            cout<<temp<<endl;
        }
        if(type==3)
        {
            int l,b,h;
            cin>>l>>b>>h;
            Box NewBox(l,b,h);
            if(NewBox<temp)
            {
                cout<<"Lesser\n";
            }
            else
            {
                cout<<"Greater\n";
            }
        }
        if(type==4)
        {
            cout<<temp.CalculateVolume()<<endl;
        }
        if(type==5)
        {
            Box NewBox(temp);
            cout<<NewBox<<endl;
        }

    }
}

int main()
{
    check2();
}