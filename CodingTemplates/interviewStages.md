## Algorithmic Interview Structure

### 1. Introductions
- At the start of the interview, most of the time your interviewer will briefly introduce themselves and their role at the company, then ask you to introduce yourself.
  - Prepare and rehearse a brief introduction of yourself. It should summarize your education, work experience, and interests in 30-60 seconds.
  - Smile and speak with a confident voice.
  - When the interviewer is talking about their work at the company, pay attention - it will help to ask questions about it later.
  - If the interviewer mentioned anything that you are also interested in, whether it be their work or a hobby, mention it.

### 2. Problem Statement
- After introductions, your interviewer will give you a problem statement. If you're working in a shared text editor, they will most likely paste the problem description along with a test case into the editor, and then read the question to you.
  - Make sure you fully understand the problem. After the interviewer has read the problem over, confirm what the problem is asking by paraphrasing it back to them.
  - Ask clarifying questions regarding the input, for example:
    - Will the input only have integers, or could there be other types?
    - Will the input be sorted or unsorted?
    - Is the input guaranteed to have elements or could it be empty?
    - What should I do if an invalid input is given?
  - Ask about the expected input size. Sometimes, the interviewer will be vague, but if they do give you a range, it can be a clue. For example, if n is very small, it is likely backtracking. If n is around 100 - 1000, an O(n^2) solution might be optimal. If n is very large, then you might need to do better than O(n).
  - The interviewer will likely give you one or two example test cases. Quickly walk through one to confirm that you understand the problem.
  - Asking clarifying questions not only helps you better understand the problem but also shows attention to detail and being considerate of things like edge cases.

### 3. Brainstorming DS&A
- Try to figure out what data structure or algorithm is applicable. Break the problem down and try to find common patterns that you've learned. Figure out what the problem needs you to do, and think about what data structure or algorithm can accomplish it with a good time complexity.
  - Think out loud. It will show your interviewer that you are good at considering tradeoffs. If the problem involves looking at subarrays, then be vocal about considering a sliding window because every window represents a subarray. Even if you're wrong, the interviewer will still appreciate your thought process.
  - The best way to train this skill is to practice LeetCode problems.
  - By thinking out loud, you also open the door for the interviewer to give you hints and point you in the right direction.
  - Once you have decided on what data structures/algorithms to use, you now need to construct your actual algorithm. Before coding, you should think of the rough steps of the algorithm, explain them to the interviewer, and make sure they understand and agree that it is a reasonable approach. Usually, if you are on the wrong path, they will subtly hint at it.
  - It is extremely important that you are receptive to what the interviewer says at this stage. Remember: they know the optimal solution. If they are giving you a hint, it is because they want you to succeed. Don't be stubborn and be ready to explore the ideas they give you.

### 4. Implementation
- Once you have come up with an algorithm and gotten the interviewer on board, it is time to start writing code.
  - If you intend on using a library or module like Python's collections for example, make sure the interviewer is ok with it before importing it.
  - As you implement, explain your decision-making. For example, if you are solving a graph problem, when you declare a set seen, explain that it is to prevent visiting the same node more than once, thus also preventing cycles.
  - Write clean code. Every major programming language has a convention for how code should be written. Make sure you know the basics of the language that you plan to be using. Google provides a summary for all major languages. The most important sections are case conventions, indentations, spacing, and global variables.
  - Avoid duplicated code. For example, if you are doing a DFS on a matrix, loop over a directions array [(0, 1), (1, 0), (0, -1), (-1, 0)] instead of writing the same logic 4 times for each direction. If you find yourself writing similar code in multiple places, consider creating a function or simplifying it with a loop.
  - Don't be scared of using helper functions. They make your code more modular, which is very important in real software engineering. It might also make potential follow-ups easier.
  - Don't panic if you get stuck or realize that your original plan might not work. Communicate your concerns with your interviewer. It makes their life a lot harder if you are struggling in silence.
  - One strategy is to first implement a brute force solution while acknowledging that it is a suboptimal solution. Once it is completed, analyze each part of the algorithm, figure out what steps are "slow", and try to think about how it can be sped up. Engage your interviewer and include them in the discussion - they want to help.

### 5. Testing & Debugging
- Once you have finished coding, your interviewer will likely want to test your code. Depending on the company, there are a few different environments your interview might be taking place in:
  - **Built-in test cases, code is run:**
    - These platforms are similar to LeetCode. There will be a wide variety of test cases - small inputs, huge inputs, inputs that test edge cases.
    - This environment puts the most stress on your code because a non-perfect solution will be exposed.
    - However, it also puts the least stress on creating your own tests, since they are already built-in.
  - **Write your own test cases, code is run:**
    - These platforms are usually shared text editors that support running code. The interviewer will want you to write your own test cases.
    - To actually test the code, you should write in the outermost scope of the code, wherever the code will get run first. Assuming you solved the problem in a function (like on LeetCode), you can call your function with the test cases you wrote and print the results to the console.
    - When writing your own tests, make sure to try a variety. Include edge cases, intuitive inputs, and possibly invalid inputs (if the interviewer wants you to handle that case).
- **Write your own test cases, code is not run:**
    - These platforms will just be shared text editors that do not support running code. The interviewer will want you to write your own test cases and walk through them manually.
    - To "test" the code, you will have to go through the algorithm manually with each test case. Try to condense trivial parts - for example, if you're creating a prefix sum, don't literally walk through the for loop with every element.
      Say something along the lines of "after this for loop, we will have a prefix sum which will look like ...".
    - As you are walking through the code, write (in the editor, outside your function somewhere) the variables used in the function and continuously update them.
    - Regardless of the scenario, if it turns out your code has an error, don't panic! If the environment supports running code, put print statements in relevant locations to try to identify the issue. Walk through a test case manually (as you would if you have an environment without runtime support) with a small test case. As you do it, talk about what the expected values of the variables should be and compare them with what they actually are. Again, the more vocal you are, the easier it is for the interviewer to help you.

### 6. Explanations and Follow-ups
- After coding the algorithm and running through test cases, be prepared to answer questions regarding your algorithm. Questions you should always expect and be ready for include:
  - What is the time and space complexity of the algorithm?
    - You should speak in terms of the worst-case scenario. However, if the worst case is rare and the average case has a significantly faster runtime, you should also mention this.
  - Why did you choose to do ...?
    - This could be your choice of data structure, choice of algorithm, choice of for loop configurations, etc. Be prepared to explain your thought process.
  - Do you think that the algorithm could be improved in terms of time or space complexity?
    - If the problem needs to look at every element in the input (let's say the input isn't sorted and you needed to find the max element), then you probably can't do better than O(n). Otherwise, you probably can't do better than O(logn).
    - If the interviewer asks this, the answer is usually yes. Be careful about asserting that your algorithm is optimal - it's ok to be wrong, but it's not ok to be confidently wrong.
  - If there is time remaining in the interview, you may be asked an entirely new question. In that case, restart from step 2 (Problem statement). However, you may also be asked follow-ups to the question you already solved. The interviewer might introduce new constraints, ask for an improved space complexity, or any other number of things.
    - This section is why it is important to actually understand solutions and not just memorize them.

### 7. Outro
- The interviewer will usually reserve a few minutes at the end of the interview to allow you to ask questions about them or the company. You will rarely be able to improve the outcome of the interview at this point, but you can certainly make it worse.
  - Interviews are a two-way street. You should use this time as an opportunity to also get to know the company and see if you would like to work there. You should prepare some questions before the interview, such as:
    - What does an average day look like?
    - Why did you decide to join this company instead of another one?
    - What is your favorite and least favorite thing about the job?
    - What kind of work can I expect to work on?
  - All big companies will have their own tech blog. A great way to demonstrate your interest in the company is to read some blog posts and compile a list of questions regarding why the company makes the decisions they do.
  - Be interested, keep smiling, listen to the interviewer's responses, and ask follow-up questions to show that you understand their answers.
  - If you don't have quality questions or appear bored/uninterested, it could give a bad signal to the interviewer. It doesn't matter how well you did on the technical portion if the interviewer doesn't like you in the end.