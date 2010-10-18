<?php
// $Id$

/**
 * Implements hook_styleguide().
 */
function styleguide_styleguide() {
  $items = array(
    'a' => array(
      'title' => 'Link',
      'content' => ucfirst(styleguide_word(3)) . ' ' . l(styleguide_word(3), 'node') . ' ' . styleguide_word(4) . '.',
    ),
    'em' => array(
      'title' => 'Emphasis',
      'content' => ucfirst(styleguide_word(3)) . ' <em>' . styleguide_word(3) . '</em> ' . styleguide_word(4) . '.',
    ),
    'strong' => array(
      'title' => 'Strong',
      'content' => ucfirst(styleguide_word(3)) . ' <strong>' . styleguide_word(3) . '</strong> ' . styleguide_word(4) . '.',
    ),
    'ul' => array(
      'title' => 'Unordered list',
      'theme' => 'item_list',
      'variables' => array('items' => styleguide_list(), 'type' => 'ul'),
    ),
    'ol' => array(
      'title' => 'Ordered list',
      'theme' => 'item_list',
      'variables' => array('items' => styleguide_list(), 'type' => 'ol'),
    ),
    'ul_title' => array(
      'title' => 'Unordered list, with title',
      'theme' => 'item_list',
      'variables' => array('items' => styleguide_list(), 'type' => 'ul', 'title' => ucwords(styleguide_word())),
    ),
    'ol_title' => array(
      'title' => 'Ordered list, with title',
      'theme' => 'item_list',
      'variables' => array('items' => styleguide_list(), 'type' => 'ol', 'title' => ucwords(styleguide_word())),
    ),
    'menu_tree' => array(
      'title' => 'Menu tree',
      'content' => drupal_render(menu_tree('management')),
    ),
    'table' => array(
      'title' => 'Table',
      'theme' => 'table',
      'variables' => array('header' => styleguide_header(), 'rows' => styleguide_rows()),
    ),
    'text' => array(
      'title' => 'Text block',
      'content' => styleguide_paragraph(3),
    ),
    'image-horizontal' => array(
      'title' => 'Image, horizontal',
      'theme' => 'image',
      'variables' => array('path' => styleguide_image('horizontal'), 'alt' => t('My image'), 'title' => t('My image')),
    ),
    'image-vertical' => array(
      'title' => 'Image, vertical',
      'theme' => 'image',
      'variables' => array('path' => styleguide_image('vertical'), 'alt' => t('My image'), 'title' => t('My image')),
    ),
  );
  $content = '';
  for ($i = 1; $i <=6; $i++) {
    $content .= "<h$i>" . "h$i: " . implode(' ', styleguide_list()) . "</h$i>";
  }
  $items["headings"] = array(
    'title' => "Headings",
    'content' => $content,
  );
  $content = '';
  for ($i = 1; $i <=6; $i++) {
    $content .= "<h$i>" . "h$i: " . implode(' ', styleguide_list()) . "</h$i>" . styleguide_paragraph(1);
  }
  $items["headings_text"] = array(
    'title' => "Headings with text",
    'content' => $content,
  );

  $messages = array('status', 'warning', 'error');
  foreach ($messages as $message) {
    $items[$message . '-message'] = array(
      'title' => ucwords($message) . ' message',
      'content' => '<div class="messages ' . $message . '"><h2 class="element-invisible">Status message</h2>' . styleguide_sentence() . '</div>',
    );
  }
  $items['form'] = array(
    'title' => 'Forms',
    'content' => drupal_render(drupal_get_form('styleguide_form')),
  );
  return $items;
}
