echo $(( (a=12,b=13,c=14),a*b<<c ))
echo $a $b $c $d $e $f $i $j $k
echo $(( (a=-42,b=42),c*=a==b||b>a?c=33,(1<<1)|1:44 ))
echo $a $b $c $d $e $f $i $j $k
echo $(( (a=1,b=2,c=3,d=4),(e=5,f=g=h=-7),i=13,j=k=33 ))
echo $a $b $c $d $e $f $i $j $k
echo $(( a+=b-=c*=d/=e%=f|=g&=h^=i<<=j>>=k=42 ))
echo $a $b $c $d $e $f $i $j $k
echo $(( (a+=1)<=12 ))
echo $a $b $c $d $e $f $i $j $k
echo $(( (a+=12)<=12 ))
echo $a $b $c $d $e $f $i $j $k
echo $(( (b=33,c=76),a=b<c?a=b>c?~b: ! ~b,~b:~c ))
echo $a $b $c $d $e $f $i $j $k
