/*
 * Your Stylesheet
 *
 * This stylesheet is loaded when Atom starts up and is reloaded automatically
 * when it is changed and saved.
 *
 * Add your own CSS or Less to fully customize Atom.
 * If you are unfamiliar with Less, you can read more about it here:
 * http://lesscss.org
 */


/*
 * Examples
 * (To see them, uncomment and save)
 */

// style the background color of the tree view
.tree-view {
  // background-color: whitesmoke;
}

// style the background and foreground colors on the atom-text-editor-element itself
atom-text-editor {
  // color: white;
  background-color: hsl(180, 24%, 12%);
 //  animation: background-color-change 1s infinite;
 //  @keyframes background-color-change {
 //   0% { background-color: red; }
 //   10% { background-color: orange; }
 //   20% { background-color: yellow; }
 //   30% { background-color: green; }
 //   40% { background-color: blue; }
 //   50% { background-color: purple; }
 //   60% { background-color: indigo; }
 //   70% { background-color: violet; }
 //   80% { background-color: cyan; }
 //   90% { background-color: maroon; }
 //   100% { background-color: red; }
 // }
}

// style UI elements inside atom-text-editor
atom-text-editor .cursor {
  border-color: whitesmoke;
  // animation: border-color-change 10s infinite;
  // @keyframes border-color-change {
  //   0% { border-color: red; }
  //   10% { border-color: orange; }
  //   20% { border-color: yellow; }
  //   30% { border-color: green; }
  //   40% { border-color: blue; }
  //   50% { border-color: purple; }
  //   60% { border-color: indigo; }
  //   70% { border-color: violet; }
  //   80% { border-color: cyan; }
  //   90% { border-color: maroon; }
  //   100% { border-color: red; }
  // }
}

atom-text-editor .syntax--comment {
  // color:#d9d1f0;
    animation: color-change 4s infinite;
    @keyframes color-change {
      0% { color: #d9d1f0; }
      50% { color: #dd9ed7; }
      100% { color: #d9d1f0; }
    }
}
