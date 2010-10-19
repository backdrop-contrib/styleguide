<?php
// $Id$

/**
 * Register a style guide element for display.
 *
 * hook_styleguide() defines an array of items to render for theme
 * testing. Each item is rendered as an element on the style guide page.
 *
 * Each item should be keyed with a unique identifier. This value will be
 * used to create a named anchor link on the Style Guide page.
 *
 * Options:
 *   -- 'title' (required). A string indicating the element name. This value
 *    will be passed to t() automatically.
 *   -- 'theme' (optional). A string indicating the theme function to invoke.
 *    If used, you must return a 'variables' array element. Otherwise, you
 *    must return a 'content' string.
 *   -- 'variables' (optional). An array of named vairables to pass to the
 *    theme function. This structure is designed to let you test your theme
 *    functions for syntax.
 *   -- 'content' (optional). A string of content to present. May be used
 *    in conjunction with a 'tag' element, or used instead of a theme callback.
 *   -- 'tag' (optional). A string indicating a valid HTML tag (wihout <>).
 *    This tag will be wrapped around the content.
 *   -- TODO: 'attributes' for a tag element.
 *   -- 'group' (optional). A string indicating the context of this element.
 *    Groups are organized within the preview interface. If no group is
 *    provided, the item will be assigned to the 'Common' group. This value
 *    will be passed to t() automatically.
 *
 * @return $items
 *   An array of items to render.
 */
function hook_styleguide() {
  $items = array(
    'ul' => array(
      'title' => 'Unordered list',
      'theme' => 'item_list',
      'variables' => array('items' => styleguide_list(), 'type' => 'ul'),
      'group' => 'Common',
    ),
    'text' => array(
      'title' => 'Text block',
      'content' => styleguide_paragraph(3),
      'group' => 'Text',
    ),
    'h1' => array(
      'title' => 'Text block',
      'tag' => 'h1',
      'content' => styleguide_word(3),
      'group' => 'Text',
    ),

  );
  return $items;
}

/**
 * 
