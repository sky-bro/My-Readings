## Basics

* viewport: a user's visible area of a web page
* Pixel density: Pixel Per Inch(PPI) or Dots Per Inch(DPI)

## CSS Selectors

* `:root` selects the root element, generally it's the `html` element

## Texts

* **font-size**

* **font-weight**

* **line-height**: the height of each line

* **text-align**

  * ```css
    p {
        text-align: center; /* justify, left, right */
    }
    ```

* **text-transform**

  * |    Value     |                         Result                         |
    | :----------: | :----------------------------------------------------: |
    | `lowercase`  |                     "transform me"                     |
    | `uppercase`  |                     "TRANSFORM ME"                     |
    | `capitalize` |                     "Transform Me"                     |
    |  `initial`   |                 Use the default value                  |
    |  `inherit`   | Use the `text-transform` value from the parent element |
    |    `none`    |           **Default:** Use the original text           |

## IMG

* Set the `width` and `height` of the `img` tag to half of their original values -- (in case retina displays,)
  * some images that have not been made with a High-Resolution Display in mind could look "pixelated" when rendered on a High-Resolution display.

## Colors

* **Complementary colors**

  * <u>opposite colors</u> on the color wheel can make each other appear <u>more vibrant</u> when placed side-by-side

  * In practice, one of the colors is usually <u>dominant</u> (use more) and the complement is used to bring <u>visual attention</u> (use less) to certain content on the page

  * ```css
    red (#FF0000) and cyan (#00FFFF)
    green (#00FF00) and magenta (#FF00FF)
    blue (#0000FF) and yellow (#FFFF00)
    ```

  * split-complement scheme

    * starts with a base color, then pairs it with the two colors that are adjacent to its complement

    * |   Color   | Hex Code |
      | :-------: | :------: |
      |  orange   | #FF7F00  |
      |   cyan    | #00FFFF  |
      | raspberry | #FF007F  |

* `#FF0000` `red` `rgb(255, 0, 0)` `rgba(255, 0, 0, 1)` `hsl(0, 100%, 50%)`

  * hsl

    * |  Color  |         HSL         |
      | :-----: | :-----------------: |
      |   red   |  hsl(0, 100%, 50%)  |
      | yellow  | hsl(60, 100%, 50%)  |
      |  green  | hsl(120, 100%, 50%) |
      |  cyan   | hsl(180, 100%, 50%) |
      |  blue   | hsl(240, 100%, 50%) |
      | magenta | hsl(300, 100%, 50%) |

    * **Hue**

      * color wheel, 0~360, from red to green, then blue

    * **Saturation**

      * amount of <u>gray</u> in a color, a fully saturated color has no gray in it
      * 100% (fully saturated)

    * **Lightness**

      * amount of <u>white or black</u> in a color
      * 0% (black), 50% (normal), 100% (white)

  * `background-color: transparent;`

* **linear-gradient**

* **repeating-linear-gradient**

  * make stripes

  * ```css
    repeating-linear-gradient(
        45deg,
        yellow 0px,
        yellow 40px,
        black 40px,
        black 80px
    );
    ```

* **url**

  * ```css
    body {
        background: url("https://cdn-media-1.freecodecamp.org/imgr/MJAkxbh.png");
    }
    ```

  * 

## Effects

* **box-shadow**

  * ```css
    /* offset-x, offset-y, blur-radius, spread-radius, color */
    #thumnail {
    	/* multiple shadows separated with comma */    
        box-shadow: 0 10px 20px rgba(0,0,0,0.19), 0 6px 6px rgba(0,0,0,0.23);
    }
    ```

* **opacity**

  * ```css
    .links {
        opacity: 0.7; /* 1: not transparent at all, 0: completely transparent */
    }
    ```

* **transform**

  * ```css
    /* doubles the size of all the paragraph elements */
    p {
      transform: scale(2);
    }
    
    p:hover {
        transform: scale(2.1);
    }
    ```

  * ```css
    /* Skew the element by -32 degrees along the X-axis */
    p {
      transform: skewX(-32deg);
    }
    
    #top {
        background-color: red;
        transform: skewY(-10deg);
    }
    #bottom {
        background-color: blue;
        transform: skewX(24deg);
    }
    ```

* **@keyframes** and **animation**

  * animation-name

  * animation-duration

  * animation-fill-mode: `forwards;`

  * animation-iteration-count: `3;` `infinite;`

  * animation-timing-function: 

    * `ease`(slow-fast-slow) 
    * `ease-in`(slow-fast) 
    * `ease-out`(fast-slow) `linear`(constant),
    * `cubic-bezier(x1, y1, x2, y2)` (x: time, y: change. range: (0,1), y could > 1, not quite understand yet )

  * ```css
    #anim {
      animation-name: colorful;
      animation-duration: 3s;
    }
    
    @keyframes colorful {
      0% {
        background-color: blue;
      }
      100% {
        background-color: yellow;
      }
    }
    ```

* Improve Readability with High **Contrast** Text

  * calculated by comparing the relative luminance values of two colors
  * The Web Content Accessibility Guidelines (WCAG) recommend <u>at least a 4.5 to 1 contrast ratio</u> for normal text
  * ranges from 1:1 for the <u>same color</u>, or no contrast, to 21:1 for <u>white against black</u>, the strongest contrast
  * links: **contrast checking calculators**,  **color picking tools** (include visual simulations of how colors appear for different types of colorblindness)

* **accesskey**

  * HTML5 allows this attribute to be used on any element, but it's particularly useful when it's used with interactive ones. This includes links, buttons, and form controls

  * ```html
    <button accesskey="b">Important Button</button>
    ```

* **tabindex**

  * negative, 0, positive

  * ```html
    <style>
      p:focus {
        background-color: yellow;
      }
    </style>
    <p tabindex="0">Instructions: Fill in ALL your information then click <b>Submit</b></p>
    ```

  * Setting a tabindex="1" will bring keyboard focus to that element first. Then it cycles through the sequence of specified `tabindex` values (2, 3, etc.), before moving to default and `tabindex="0"` items.

    * ```html
      <div tabindex="1">I get keyboard focus, and I get it first!</div>
      
      <div tabindex="2">I get keyboard focus, and I get it second!</div>
      ```

    * 

## Positioning & Layout

* **position**

  * **relative**
    * pair with `top` `bottom` `left` `right`, tell the browser how far to offset an item relative to where it would sit in the <u>normal flow</u> of the document
  * **absolute**
    * locked relative to its <u>closest positioned ancestor</u>
    * If you forget to add a position rule to the parent item, (this is typically done using `position: relative;`) browser will keep looking up the chain (without `position: relative`) and ultimately default to the <u>body</u> tag.
    * this will **remove** the element from its normal flow (other items will ignore this element)
  * **fixed**
    * like <u>absolute</u>, but positioned relative to the <u>viewport</u> (window)
  * **sticky**

* **z-index**

  * When elements are positioned to overlap (i.e. using `position: absolute | relative | fixed | sticky`)
  * element coming later in the HTML markup will, by default, appear on the top of the other elements
  * <u>higher values</u> for the `z-index` property of an element move it <u>higher in the stack</u> than those with lower values

* **float**

  * ```css
    #left {
        float: left;
        width: 50%;
    }
    #right {
        float: right;
        width: 40%;
    }
    ```

* **margin**

  * center a <u>block</u> element horizontally using: `margin: auto;`
    * to center an image, change `img`'s display property to `block` (`inline block`?)
  
* **Flex**

  * **flex-direction**: `row` (default), `column`, `row-reverse`, `column-reverse`

  * **justify-content**: (<u>main axis</u>) `center`, `flex-start` (default), `flex-end`, `space-between`, `space-around`, `space-evenly`

  * **align-items**: (<u>cross axis</u>) `flex-start`, `flex-end`, `center`, `stretch` (default), `baseline`

  * **flex-wrap**: `nowrap` (default), `wrap`, `wrap-reverse`

  * **flex-shrink**: applied on <u>flex items</u>

    * if one item has a `flex-shrink` value of `1` and the other has a `flex-shrink` value of `3`, the one with the value of `3` will shrink three times as much as the other.

  * **flex-grow**: (like `flex-shrink`, this allows flex items to grow)

  * **flex-basis**: specifies the initial size of the item before CSS makes adjustments with `flex-shrink` or `flex-grow`.

  * **flex**: flex short hand

    * For example, `flex: 1 0 10px;` will set the item to `flex-grow: 1;`, `flex-shrink: 0;`, and `flex-basis: 10px;`

    *  default property settings are `flex: 0 1 auto;`

    * ```css
      #box-container {
          display: flex;
          height: 500px;
      }
      #box-1 {
          background-color: dodgerblue;
          flex: 2 2 150px;
          height: 200px;
      }
      
      #box-2 {
          background-color: orangered;
          flex: 1 1 150px;
          height: 200px;
      }
      ```

  * **order**

    * tell CSS the order of how flex items appear in the flex container
    * negative numbers can be used.

  * **align-self**

    * `align-self` accepts the same values as `align-items` and will override any value set by the `align-items` property
    * allows you to adjust each item's alignment individually

* **Grid**

  * `display: grid;`

  * **grid-template-columns**, **grid-template-rows**

    * ```css
      .container {
          font-size: 40px;
          width: 100%;
          background: LightGray;
          display: grid;
          grid-template-columns: 100px 100px 100px; /* 3 columns, each with 100px width */
          grid-template-rows: 50px 50px; /* 2 rows, each with 50px height */
      }
      ```

    * `auto` `%` `fr` (sets the column or row to a fraction of the available space): `  grid-template-columns: auto 50px 10% 2fr 1fr;`

    * use **repeat**, **minmax** functions:

      * ```css
        grid-template-columns: repeat(2, 1fr 50px) 20px;
        /* grid-template-columns: 1fr 50px 1fr 50px 20px; */
        
        grid-template-columns: repeat(3,minmax(90px, 1fr));
        ```
  
      * **auto-fill**, **auto-fit**
  
        * ```css
        /* repeat function comes with an option called auto-fill. */
          /*  If your container can't fit all your items on one row, it will move them down to a new one */
          repeat(auto-fill, minmax(60px, 1fr));
          
          /* auto-fit works almost identically to auto-fill. when the container's size exceeds the size of all the items combined, auto-fit collapses those empty rows or columns and stretches your items to fit the size of the container. */
          repeat(auto-fit, minmax(60px, 1fr)); /* better than auto-fill */
          ```
          
        * 
  
  * **grid-column-gap**, **grid-row-gap**, **grid-gap**
  
    * `grid-gap` is a shorthand property for `grid-row-gap` and `grid-column-gap`
    
    * ```css
      grid-gap: 10px 20px; /* row, column*/
      /* if only one value, create gap between all rows and columns*/
      ```
    
  * **grid-column**, **grid-row** (applied on grid items)
  
    * ```css
      grid-column: 2/4; /* take the 2 and 3 columns*/
      grid-row: 1/3; /* take the 1 and 2 rows */
      ```
  
  * **justify-self**
  
    * `start` `center` `end` `stretch` (default)
    *  align the content's position within its cell <u>horizontally</u> 
  
  * **align-self**
  
    * `start` `center` `end` `stretch` (default)
    * align an item <u>vertically</u>
  
  * **justify-items**
  
  * **align-items**
  
  * **grid-template-areas**, **grid-area**
  
    * ```css
      .item5 {
          background: PaleGreen;
          grid-area: footer; /* taks the 3 footer areas */
      }
      
      .container {
          font-size: 40px;
          min-height: 300px;
          width: 100%;
          background: LightGray;
          display: grid;
          grid-template-columns: 1fr 1fr 1fr;
          grid-template-rows: 1fr 1fr 1fr;
          grid-gap: 10px;
          grid-template-areas:
              "header header header"
              "advert content content"
              "footer footer footer";
      }
      
      /* grid-area: horizontal line to start at / vertical line to start at / horizontal line to end at / vertical line to end at; /*
      /* create area on the fly */
      item1 { grid-area: 1/1/2/4; }
      ```
  
    * 

## Responsive

* **media queries**

  * ```css
    /* when the device's width is less than or equal to 100px */
    @media (max-width: 100px) { /* CSS Rules */ }
    
    /* when the device's height is more than or equal to 350px */
    @media (min-height: 350px) { /* CSS Rules */ }
    
    p {
        font-size: 20px;
    }
    
    @media (max-height: 800px) {
        p {font-size: 10px;}
    }
    ```

* **responsive image**

  * ```css
    img {
      max-width: 100%; /* make sure the image is never wider than the container it is in */
      height: auto; /* keep its original aspect ratio */
    }
    ```

* **make typography responsive**

  * `vw` (viewport width): `10vw` would be 10% of the viewport's width.
  * `vh` (viewport height): `3vh` would be 3% of the viewport's height.
  * `vmin` (viewport minimum): `70vmin` would be 70% of the viewport's smaller dimension (height or width).
  * `vmax` (viewport maximum): `100vmax` would be 100% of the viewport's bigger dimension (height or width).