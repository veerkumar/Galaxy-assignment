
# Galaxy-assignment
<b>Problem statement:</b> You decided to give up on earth after the latest financial collapse left 99.99% of the earth's population with
0.01% of the wealth. Luckily, with the scant sum of money that is left in your account, you are able to afford to
rent a spaceship, leave earth, and fly all over the galaxy to sell common metals and dirt (which apparently is
worth a lot).Buying and selling over the galaxy requires you to convert numbers and units, and you decided to
write a program to help you.The numbers used for intergalactic transactions follows similar convention to the
roman numerals and you have painstakingly collected the appropriate translation between them. <b>For more check the pdf.</b>

<b>Assumption:</b> Input statment structure/grammer should be same as given in sample input. To support generic, we will need NLP to get the true meaning.<br>
To expand in more detail:-<br>
1) Its assumed that each line is terminated by newline. Ex: Testcase given in question <br>
2) Questions are assumed to be end with '?' (without quotes). Ex: how much is glob pish ? <br>
3) Inputs are assumed to be case sensitive. Ex: glob is not GLOB.<br>
4) keyword 'is' is assumed as a separator for identifiers and their values in Assignment statement. Ex: glob is I <br>
5) Whenever you provide empty line the input process will be terminated.<br>
6) Roman numbers must be specified in capitals.<br>

<b>Solution:</b> It is divided into two parts:<br>
		1) Learning(grammer and metal pricing) <br>
		2) Questionnaire <br>
<p> Solution is written such a way that learning and question can be executed in any sequence. which means if knowledge base is set, question will fetch the answer else not. it is done by keeping in mind that galaxy language may evolve or metal price can change. </p> 
 
Test case:1<br>
glob is I <br>
prok is V <br>
pish is X <br>
tegj is L <br>
glob glob Silver is 34 Credits<br>
glob prok Gold is 57800 Credits<br>
pish pish Iron is 3910 Credits<br>
how much is pish tegj glob glob ?<br>
how many Credits is glob prok Silver ?<br>
how many Credits is glob prok Gold ?<br>
how many Credits is glob prok Iron ?<br>
how much wood could a woodchuck chuck if a woodchuck could chuck wood ?<br>
Test Output:<br>
pish tegj glob glob is 42.0000<br>
glob prok Silver is 68.0000 Credits<br>
glob prok Gold is 57800.0000 Credits<br>
glob prok Iron is 782.0000 Credits<br>
I have no idea what you are talking about<br>


Test case2:<br>
glob is I<br>
prok is V<br>
pish is X<br>
tegj is L<br>
glob glob Silver is 34 Credits<br>
glob prok Gold is 57800 Credits<br>
pish pish Iron is 3910 Credits<br>
how much is pish tegj glob glob ?<br>
how many Credits is glob prok Silver ?<br>
how many Credits is glob prok Gold ?<br>
how many Credits is glob prok Iron ?<br>
how much wood could a woodchuck chuck if a woodchuck could chuck wood ?<br>
how much is pramod pish glob glob ?<br>
pramod is D<br>
how much is pramod pish glob glob ?<br>

output:<br>
pish tegj glob glob  is 42<br>
glob prok Silver is 68.000000 Credits<br>
glob prok Gold is 57800.000000 Credits<br>
glob prok Iron is 782.000000 Credits<br>
I have no idea what you are talking about<br>
I have no idea what you are talking about<br>
pramod pish glob glob  is 512<br>
