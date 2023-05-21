# Maximum number of unique prime factors
## Easy
<div class="problems_problem_content__Xm_eO"><p><span style="font-size:18px">Given a number <strong>N</strong>, find the maximum number of unique prime factors any number can have in range [1, N].</span></p>

<p><span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:</strong></span>
<span style="font-size:18px"><strong>N = </strong>3</span>
<span style="font-size:18px"><strong>Output:</strong></span>
<span style="font-size:18px">1</span>
<span style="font-size:18px"><strong>Explanation:</strong></span>
<span style="font-size:18px">No number in the range 1 to 3
can have more than 1 unique
Prime factor. So, the Output is 1.</span></pre>

<p><span style="font-size:18px"><strong>Example 2:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:</strong></span>
<span style="font-size:18px"><strong>N = </strong>500</span>
<span style="font-size:18px"><strong>Output:</strong></span>
<span style="font-size:18px">4</span>
<span style="font-size:18px"><strong>Explanation:</strong></span>
<span style="font-size:18px">No number in the range 1 to 500
can have more than 4 unique
Prime factors. So, the Output is 4.
An example of a number with 4
unique Prime Factors is 210.</span>
</pre>

<p><span style="font-size:18px"><strong>Your Task:</strong><br>
You don't need to read input or print anything. Your task is to complete the function <strong>maxUniquePrimeFactors()</strong> which takes an Integer N as input and returns the answer.</span></p>

<p><span style="font-size:18px"><strong>Expected Time Complexity:</strong> O(Largest Prime Factor of N)<br>
<strong>Expected Auxiliary Space:</strong> O(1)</span></p>

<p><span style="font-size:18px"><strong>Constraints:</strong></span><br>
<span style="font-size:18px">1 &lt;= N &lt;= 10<sup>18</sup></span></p>
</div>