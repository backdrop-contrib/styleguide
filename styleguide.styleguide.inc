<?php
// $Id$

/**
 * Implements hook_styleguide().
 */
function styleguide_styleguide() {
  $items = array(
    'a' => array(
      'title' => 'Link',
      'content' => l(styleguide_word(), 'node'),
    ),
    'em' => array(
      'title' => 'Emphasis',
      'tag' => 'em',
      'content' => styleguide_word(),
    ),
    'strong' => array(
      'title' => 'Strong',
      'tag' => 'strong',
      'content' => styleguide_word(),
    ),
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
    'image-horizontal' => array(
      'title' => 'Image, horizontal',
      'theme' => 'image',
      'arguments' => array('path' => styleguide_image('horizontal'), 'alt' => t('My image'), 'title' => t('My image')),
    ),
    'image-vertical' => array(
      'title' => 'Image, vertical',
      'theme' => 'image',
      'arguments' => array('path' => styleguide_image('vertical'), 'alt' => t('My image'), 'title' => t('My image')),
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
