两个已经排好序的链表，这里采用的是选取一个表头较小的链表作为基准，用另一个链表进行插入操作。    
那么两个链表可以表示为：    
`baselist`      --->      `basenext`      
`insertlist`    --->      `insertnext`       
对于`basenext->val`小于`insertlist->val`的情况，`baselist`继续向前。       
否则将`insertlist`插入到`baselist`链表中。       
`baselist`      --->      `insertlist`    --->      `basenext`        
`insertnext`       
之后将`baselist`置为`insertlist`，`insertlist`置为`insertnext`。       
当结束时有两种情况，第一种是`insertnext`先用完了，那么退出，另一种情况是，`baselist`先用完了，那么将`baselist`的`next`与`insertnext`接上即可。      