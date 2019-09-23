# Questions

## What is pneumonoultramicroscopicsilicovolcanoconiosis?

An artificial long word said to mean a lung disease caused by inhaling very fine ash and sand dust.

## According to its man page, what does `getrusage` do?

get resource usage

## Per that same man page, how many members are in a variable of type `struct rusage`?

16

## Why do you think we pass `before` and `after` by reference (instead of by value) to `calculate`, even though we're not changing their contents?

Not sure

## Explain as precisely as possible, in a paragraph or more, how `main` goes about reading words from a file. In other words, convince us that you indeed understand how that function's `for` loop works.



## Why do you think we used `fgetc` to read each word's characters one at a time rather than use `fscanf` with a format string like `"%s"` to read whole words at a time? Put another way, what problems might arise by relying on `fscanf` alone?

They could be randomly capitalized and you want to compare those words to words that are lowercase.

## Why do you think we declared the parameters for `check` and `load` as `const` (which means "constant")?

So the words wouldn't change.
