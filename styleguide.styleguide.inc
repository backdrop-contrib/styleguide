<?php
// $Id$

/**
 * Implements hook_styleguide().
 */
function styleguide_styleguide() {
  $items = array(
    'ul' => array(
      'title' => 'Unordered list',
      'theme' => 'item_list',
      'arguments' => array('items' => styleguide_list(), 'type' => 'ul'),
    ),
    'ol' => array(
      'title' => 'Ordered list',
      'theme' => 'item_list',
      'arguments' => array('items' => styleguide_list(), 'type' => 'ol'),
    ),
    'ul_title' => array(
      'title' => 'Unordered list, with title',
      'theme' => 'item_list',
      'arguments' => array('items' => styleguide_list(), 'type' => 'ul', 'title' => ucwords(styleguide_word())),
    ),
    'ol_title' => array(
      'title' => 'Ordered list, with title',
      'theme' => 'item_list',
      'arguments' => array('items' => styleguide_list(), 'type' => 'ol', 'title' => ucwords(styleguide_word())),
    ),
    'menu_tree' => array(
      'title' => 'Menu tree',
      'content' => drupal_render(menu_tree('management')),
    ),
    'table' => array(
      'title' => 'Table',
      'theme' => 'table',
      'arguments' => array('header' => styleguide_header(), 'rows' => styleguide_rows()),
    ),
    'text' => array(
      'title' => 'Text block',
      'content' => styleguide_paragraph(3),
    ),
  );
  for ($i = 1; $i <=6; $i++) {
    $items["h$i"] = array(
      'title' => "Header $i",
      'tag' => "h$i",
      'content' => implode(' ', styleguide_list()),
    );
  }
  return $items;
}
