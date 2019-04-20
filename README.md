
# Galaxy-assignment
Problem statement: You decided to give up on earth after the latest financial collapse left 99.99% of the earth's population with
0.01% of the wealth. Luckily, with the scant sum of money that is left in your account, you are able to afford to
rent a spaceship, leave earth, and fly all over the galaxy to sell common metals and dirt (which apparently is
worth a lot).Buying and selling over the galaxy requires you to convert numbers and units, and you decided to
write a program to help you.The numbers used for intergalactic transactions follows similar convention to the
roman numerals and you have painstakingly collected the appropriate translation between them. For more check the pdf.

Assumption: Input statment structure/grammer will be same else we will need NLP to get the true meaning.

Solution: It is divided into two parts:
		1) Learning(grammer and metal pricing)
		2) Questionnaire
solution is written such a way that learning and question can be executed in any sequence. which means if knowledge base is set, question will fetch the answer else not. it is done by keeping in mind that galaxy language may evolve or metal price can change. 
 
Test case:1
glob is I
prok is V
pish is X
tegj is L
glob glob Silver is 34 Credits
glob prok Gold is 57800 Credits
pish pish Iron is 3910 Credits
how much is pish tegj glob glob ?
how many Credits is glob prok Silver ?
how many Credits is glob prok Gold ?
how many Credits is glob prok Iron ?
how much wood could a woodchuck chuck if a woodchuck could chuck wood ?
Test Output:
pish tegj glob glob is 42.0000
glob prok Silver is 68.0000 Credits
glob prok Gold is 57800.0000 Credits
glob prok Iron is 782.0000 Credits
I have no idea what you are talking about


Test case2:
glob is I
prok is V
pish is X
tegj is L
glob glob Silver is 34 Credits
glob prok Gold is 57800 Credits
pish pish Iron is 3910 Credits
how much is pish tegj glob glob ?
how many Credits is glob prok Silver ?
how many Credits is glob prok Gold ?
how many Credits is glob prok Iron ?
how much wood could a woodchuck chuck if a woodchuck could chuck wood ?
how much is pramod pish glob glob ?
pramod is D
how much is pramod pish glob glob ?

output:
pish tegj glob glob  is 42
glob prok Silver is 68.000000 Credits
glob prok Gold is 57800.000000 Credits
glob prok Iron is 782.000000 Credits
I have no idea what you are talking about
I have no idea what you are talking about
pramod pish glob glob  is 512 
