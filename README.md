# QuartoAI

A Quarto board game mimic that you can play against your friend or play against an advanced bot that will never lose!

![MainMenu](https://cloud.githubusercontent.com/assets/12219300/19020274/4048cef2-8859-11e6-9ae5-223f17347e6f.gif)

### Creating the Bot

The AI for the bot is implemented using a custom version of Negamax with Alpha-Beta pruning.  

Implementing the Negamax just requires one extra parameter in the recursive method, **NSInteger color**.
If color is positive, then it's the bot's turn.
If the color is negative, then it's the opponent's turn.

How the bot decides where to move is very similar to [TicTacToeAI](https://github.com/logicxd/TicTacToeAI) in how it looks ahead a certain number of moves with different perspectives.
It has just one change: each move has two parts to it.

![BotWins](https://cloud.githubusercontent.com/assets/12219300/19020428/63fcaca2-885d-11e6-99db-660d4264d120.gif)

The bot is given a piece to place (Quarto game rules) and the board indices.
It iterates through all the empty spots and places the piece to determine where would be a good spot to place.
At each iteration, it also has to iterate through all the pieces that are left to decide which piece to give to the opponent that will minimize the opponent's score.
The stopping point is when there are no more pieces, or a winner is found, or when it searched through just enough depths.

### Drag Animation

The animation is done by implementing these three methods from UIResponder class:

```Objective-C
- (void)touchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event;
- (void)touchesMoved:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event;
- (void)touchesEnded:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event;
```
How they work is:
* touchesBegan: Called once when finger touches the screen.
* touchesMoved: Called many times as finger moves across the screen.
* touchesEnded: Called once when finger leaves the screen.

###### Getting touched object

You can test which UIView was **initially touched** by doing this:
```Objective-C
UITouch *touch = [touches anyObject];
if ([touch.view isKindOfClass:[QuartoPiece class]]) {
  // The touched object is a Quarto Piece.
}
```
Important! In all three methods, this returns the first object that was touched, but not where the touch is released or where the finger is on top of while moving.

To test for which UIView the finger is **currently on**, you can use this:
```Objective-C
CGPoint currentTouchLocation = [touch locationInView:self.view];
UIView *viewInCurrentTouchLocation = [self.yourView hitTest:currentTouchLocation withEvent:nil];
```

###### Update touched UIView to follow your finger



### Pop-up View

---

### Acknowledgements

Thanks to Alaric, Janelle, Jessica, Justin, Monique, and Vivian (ordered alphabetically) for suggestions and inputs.

Special Thanks:
* [Alaric](https://github.com/AlaricGonzales): Button text color change on press in the main menu. Design ideas. Product testing.
* Janelle: Design ideas.
* Jessica: Design ideas. Product testing.

### Copyright(s)

Board pieces taken from [Typeicons](http://www.typicons.com) by Stephen Hutchings.
License: [CC BY-SA 3.0](https://creativecommons.org/licenses/by-sa/3.0/).
Changes:
* Removed paddings inside the icon.
* Different colors.

Settings icon taken from [Icons8](https://www.icons8.com).
License: [CC BY-ND 3.0](https://creativecommons.org/licenses/by-nd/3.0/)
