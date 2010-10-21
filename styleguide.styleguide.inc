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
      'group' => 'Lists',
    ),
    'ol' => array(
      'title' => 'Ordered list',
      'theme' => 'item_list',
      'variables' => array('items' => styleguide_list(), 'type' => 'ol'),
      'group' => 'Lists',
    ),
    'ul_title' => array(
      'title' => 'Unordered list, with title',
      'theme' => 'item_list',
      'variables' => array('items' => styleguide_list(), 'type' => 'ul', 'title' => ucwords(styleguide_word())),
      'group' => 'Lists',
    ),
    'ol_title' => array(
      'title' => 'Ordered list, with title',
      'theme' => 'item_list',
      'variables' => array('items' => styleguide_list(), 'type' => 'ol', 'title' => ucwords(styleguide_word())),
      'group' => 'Lists',
    ),
    'menu_tree' => array(
      'title' => 'Menu tree',
      'content' => drupal_render(menu_tree('management')),
      'group' => 'Menus',
    ),
    'table' => array(
      'title' => 'Table',
      'theme' => 'table',
      'variables' => array('header' => styleguide_header(), 'rows' => styleguide_rows()),
      'group' => 'Tables',
    ),
    'text' => array(
      'title' => 'Text block',
      'content' => styleguide_paragraph(3),
      'group' => 'Text',
    ),
    'image-horizontal' => array(
      'title' => 'Image, horizontal',
      'theme' => 'image',
      'variables' => array('path' => styleguide_image('horizontal'), 'alt' => t('My image'), 'title' => t('My image')),
      'group' => 'Media',
    ),
    'image-vertical' => array(
      'title' => 'Image, vertical',
      'theme' => 'image',
      'variables' => array('path' => styleguide_image('vertical'), 'alt' => t('My image'), 'title' => t('My image')),
      'group' => 'Media',
    ),
    'image-inset-horizontal' => array(
      'title' => 'Image, horizontal, within text',
      'content' => styleguide_paragraph(1) . theme('image', array('path' => styleguide_image('horizontal'), 'alt' => t('My image'), 'title' => t('My image'))) . styleguide_paragraph(2),
      'group' => 'Media',
    ),
    'image-inset-vertical' => array(
      'title' => 'Image, vertical, within text',
      'content' => styleguide_paragraph(1) . theme('image', array('path' => styleguide_image('vertical'), 'alt' => t('My image'), 'title' => t('My image'))) . styleguide_paragraph(2),
      'group' => 'Media',
    ),
  );
  $content = '';
  for ($i = 1; $i <=6; $i++) {
    $content .= "<h$i>" . "h$i: " . implode(' ', styleguide_list()) . "</h$i>";
  }
  $items["headings"] = array(
    'title' => "Headings",
    'content' => $content,
    'group' => 'Text',
  );
  $content = '';
  for ($i = 1; $i <=6; $i++) {
    $content .= "<h$i>" . "h$i: " . implode(' ', styleguide_list()) . "</h$i>" . styleguide_paragraph(1);
  }
  $items["headings_text"] = array(
    'title' => "Headings with text",
    'content' => $content,
    'group' => 'Text',
  );
  $messages = array('status', 'warning', 'error');
  foreach ($messages as $message) {
    $items[$message . '-message'] = array(
      'title' => ucwords($message) . ' message',
      'content' => '<div class="messages ' . $message . '"><h2 class="element-invisible">Status message</h2>' . styleguide_sentence() . '</div>',
    );
  }
  // Form elements.
  $fake = $form_state = array();
  $elements = styleguide_form($fake, $form_state);
  $basic = array();
  $fieldsets = array();
  $tabs = array();
  $markup = array();
  foreach (element_children($elements) as $key) {
    if (!isset($elements[$key]['#type']) || $elements[$key]['#type'] == 'item') {
      $markup[] = $key;
    }
    elseif ($elements[$key]['#type'] == 'fieldset') {
      $fieldsets[] = $key;
    }
    elseif ($key == 'vertical_tabs') {
      $tabs[] = $key;
    }
    // We skip these.
    elseif (in_array($elements[$key]['#type'], array('button', 'submit', 'image_button'))) {
      $buttons[] = $key;
    }
    else {
      $basic[] = $key;
    }
  }
  $items['form'] = array(
    'title' => 'Forms, basic',
    'content' => drupal_render(drupal_get_form('styleguide_form', $basic)),
    'group' => 'Forms',
  );
  $items['form-submit'] = array(
    'title' => 'Forms, submit',
    'content' => drupal_render(drupal_get_form('styleguide_form', array('submit'))),
    'group' => 'Forms',
  );
  $items['form-button'] = array(
    'title' => 'Forms, button',
    'content' => drupal_render(drupal_get_form('styleguide_form', array('button'))),
    'group' => 'Forms',
  );
  $items['form-image-button'] = array(
    'title' => 'Forms, image button',
    'content' => drupal_render(drupal_get_form('styleguide_form', array('image_button'))),
    'group' => 'Forms',
  );
  $items['form-markup'] = array(
    'title' => 'Forms, markup',
    'content' => drupal_render(drupal_get_form('styleguide_form', $markup)),
    'group' => 'Forms',
  );
  $items['form-fieldsets'] = array(
    'title' => 'Forms, fieldsets',
    'content' => drupal_render(drupal_get_form('styleguide_form', $fieldsets)),
    'group' => 'Forms',
  );
  $items['form-vertical-tabs'] = array(
    'title' => 'Forms, vertical tabs',
    'content' => drupal_render(drupal_get_form('styleguide_form', $tabs)),
    'group' => 'Forms',
  );

  return $items;
}
