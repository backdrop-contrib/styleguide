<?php
// $Id$

/**
 * Register a style guide element for display.
 *
 * hook_styleguide() defines an array of items to render for theme
 * testing. Each item is rendered as an element on the style guide page.
 *
 * @return $items
 *   An array of items to render.
 */
function hook_styleguide() {
  $items = array(
    'ul' => array(
      'title' => 'Unordered list',
      'theme' => 'item_list',
      'arguments' => array('items' => styleguide_list(), 'type' => 'ul'),
    ),
    'text' => array(
      'title' => 'Text block',
      'content' => styleguide_paragraph(3),
    ),
  );
  return $items;
}
