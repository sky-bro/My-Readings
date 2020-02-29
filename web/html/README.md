* semantic tags

  * header

  * nav

  * main

  * section

  * article

  * footer

  * audio

  * figure, figcaption

    * ```html
      <figure>
        <img src="roundhouseDestruction.jpeg" alt="Photo of Camper Cat executing a roundhouse kick">
        <br>
        <figcaption>
          Master Camper Cat demonstrates proper form of a roundhouse kick.
        </figcaption>
      </figure>
      ```

  * label

    * The value of the `for` attribute must be the same as the value of the `id` attribute of the form control

    * ```html
      <form>
        <label for="name">Name:</label>
        <input type="text" id="name" name="name">
      </form>
      ```

  * fieldset, legend (for description of the grouping)

    * The `fieldset` wrapper and `legend` tag are <u>not necessary</u> when the choices are self-explanatory, like a gender selection. Using a `label` with the `for` attribute for each radio button is sufficient

    * ```html
      <form>
        <fieldset>
          <legend>Choose one of these three items:</legend>
          <input id="one" type="radio" name="items" value="one">
          <label for="one">Choice One</label><br>
          <input id="two" type="radio" name="items" value="two">
          <label for="two">Choice Two</label><br>
          <input id="three" type="radio" name="items" value="three">
          <label for="three">Choice Three</label>
        </fieldset>
      </form>
      ```

  * time, datetime

    * ```html
      <p>Master Camper Cat officiated the cage match between Goro and Scorpion <time datetime="2013-02-13">last Wednesday</time>, which ended in a draw.</p>
      ```

* Date picker

  * ```html
    <label for="pickdate">Preferred Date:</label>
    <input type="date" name="date" id="pickdate">
    ```

* 