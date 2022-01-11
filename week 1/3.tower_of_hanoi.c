#include <stdio.h>
//total count
int totcount (int rod[], int totaldisk)
{
    int count = 0,i;
    for (i = 1; i <= totaldisk; ++i ) {
        if ( rod[i] == 3 )
            ++count;
    }
    return count;
}
//disk1
int disk1 (int *diskfrom, int *diskto,int rod[], int small)
{
    *diskfrom = rod[1];
    *diskto = *diskfrom + small;
    if ( *diskto > 3 )
        *diskto = 1;
    if ( *diskto < 1 )
        *diskto = 3;
    return 1;
}
//disk2
int disk2 (int *diskfrom, int *diskto,int rod[], int totaldisk)
{
    int topDisk[4];
    int i;
    for (i = 1; i <= 3; ++i )
        topDisk[i] = totaldisk + 1;
    for ( i = totaldisk; i >= 1; --i )
        topDisk[rod[i]] = i;
    if(rod[1]==1)
    {
            *diskfrom = 2;
            *diskto = 3;
	}
	else if(rod[1]==2){
            *diskfrom = 1;
            *diskto = 3;
        }
    else if(rod[1]==3){
            *diskfrom = 1;
            *diskto = 2;
    }
    if ( topDisk[*diskfrom] > topDisk[*diskto] ) {
        int temp;
        temp = *diskfrom;
        *diskfrom = *diskto;
        *diskto = temp;
    }
    return topDisk[*diskfrom];
}
int main (void)
{
    printf ("Enter number of disks ");
    int totaldisk,small,i,moveCount = 0, disk, rodFrom, rodTo;;
    scanf ("%d", &totaldisk);
    if(totaldisk <=0)
    	printf("Enter valid number of disks");
    else{
    	int rod[totaldisk + 1];
    	small=(totaldisk % 2) == 1 ? -1:1;
    	for ( i = 1; i <= totaldisk; ++i )
        rod[i] = 1;
    	while ( totcount (rod, totaldisk) != totaldisk ){
        ++moveCount;
        if ( (moveCount % 2) == 0 )
            disk = disk2 (&rodFrom, &rodTo,rod, totaldisk);
        else
        disk = disk1 (&rodFrom, &rodTo,rod, small);
        printf ("disk %d moves from rod %c to rod %c\n",disk,rodFrom + 64, rodTo + 64);
        rod[disk] = rodTo;
    	}
	}
    return 0;
}
