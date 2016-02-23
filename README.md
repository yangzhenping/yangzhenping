# yangzhenping
yangzhenping


##LongestWordInAnArticle.c
LongestWordInAnArticle.c is a program which implement search a longest word in an article.

  - Currently just support output last longest word
  - word start with '-' or end with '-' will consider a word, so need to exclude them in the future
  - Currently not support like 'What's'

Notes:
> 1. abc
> 2. def
> 3. hij

### Compile:
```sh
$ gcc LongestWordInAnArticle.c LongestWordInAnArticle
```

### Run:
```sh
$ ./LongestWordInAnArticle article1.txt
```

### Todos

 - Write Tests
 - Add Code Comments

##SumOfN-thPowersIsAnN-thPower.c
SumOfN-thPowersIsAnN-thPower.c is a program which implement Sum of n-th Powers Is an n-th Power:[sum_of_powers_is_a_power].

  - A^5 + B^5 + C^5 + D^5 + E^5 = F^5
  - 0<A<=B<=C<=D<=E<=F<=75 
  - A^5 means power(A,5)

Notes:
> 1. abc
> 2. def
> 3. hij

### Compile:
```sh
$ gcc SumOfN-thPowersIsAnN-thPower.c -lm -o SumOfN-thPowersIsAnN-thPower
```

### Run:
```sh
$ ./SumOfN-thPowersIsAnN-thPower
```
##RecursionTwoDimensionalArray.c
RecursionTwoDimensionalArray.c is a program which implement below algorithm:.

  - Consider a N*N table , among it some cell is occupied, if two cells has at least one same edge, we think they are belong to a same group.
  - You will find 3 groups with 2 cells(I marked it as 1 , 2 ,4), one group with 4 cells(3) and 2 group with only 1 cells (5,6)
  - Suppose the table is combined with a two-dimensional arrays, write a function to calculate:
  - Give you a cell in one group, please calculate the size of this group. For example , input: (1,3), output: 2
  - Calculate the count of different groups. For this example: group1 is 2, group2 is 2, group 3 is 4, group4 is 2, group 5 is 1, group 6 is 1.
  - List all groups.
  - Design the test cases.
  - For example , look at below table:
  - 0       0       0       0       0       0       0       0       0       1
  - 0       0       0       1       1       0       0       0       0       1
  - 0       0       0       0       0       0       0       0       0       0
  - 0       0       0       0       1       0       0       1       0       0
  - 0       0       0       1       0       0       0       1       0       0
  - 0       0       0       0       0       0       0       1       1       0
  - 0       0       0       0       1       1       0       0       0       0
  - 0       0       0       0       0       0       0       0       0       0
  - 0       0       0       0       0       0       0       0       0       0
  - 0       0       0       0       0       0       0       0       0       0

Notes:
> 1. abc
> 2. def
> 3. hij

### Compile:
```sh
$ gcc RecursionTwoDimensionalArray.c -o RecursionTwoDimensionalArray
```

### Run:
```sh
$ ./RecursionTwoDimensionalArray
```
### License

----

MIT




**Free Software, Hell Yeah!**
[//]: # (These are reference links used in the body of this note and get stripped out when the markdown processor does its job. There is no need to format nicely because it shouldn't be seen. Thanks SO - http://stackoverflow.com/questions/4823468/store-comments-in-markdown-syntax)



   [sum_of_powers_is_a_power]: <http://martin-flatin.org/math/sums_of_powers/sum_of_powers_is_a_power.xhtml>