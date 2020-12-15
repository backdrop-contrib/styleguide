<?php
/**
 * @file
 * Style Guide plugin file for the Comment module.
 */

/**
 * Implements hook_styleguide().
 */
function comment_styleguide() {
  global $conf, $user;
  $user_register = config_get('system.core', 'user_register');
  $account = clone $user;
  $user->uid = 0;
  $conf['comment_form_location_-styleguide-'] = COMMENT_FORM_SEPARATE_PAGE;
  config_set('system.core', 'user_register', TRUE);

  $authenticated_post_comments = &backdrop_static('theme_comment_post_forbidden', NULL);
  $authenticated_post_comments = TRUE;
  $items['comment_post_forbidden'] = array(
    'title' => t('Comment post forbidden'),
    'content' => theme('comment_post_forbidden', array('node' => (object) array('nid' => 0, 'type' => 'post'))),
    'group' => t('Comment'),
  );

  $user = $account;
  config_set('system.core', 'user_register', $user_register);

  $render = array(
    'body' => array(
      '#markup' => styleguide_paragraph(2),
    ),
    '#theme' => 'comment',
    '#comment' => new Comment(array(
      'cid' => 0,
      'pid' => 0,
      'nid' => 1,
      'uid' => 0,
      'subject' => 'foo bar',
      'hostname' => '::1',
      'created' => time(),
      'changed' => time(),
      'status' => 1,
      'thread' => '01/',
      'name' => styleguide_word(2),
      'mail' => '',
      'homepage' => 'https://backdropcms.org/project/styleguide',
      'language' => 'und',
      'node_type' => 'comment_node_styleguide',
      'registered_name' => '',
      'u_uid' => 0,
      'signature' => '',
      'signature_format' => NULL,
      'picture' => 0,
      'new' => 0,
    )),
    '#node' => new Node(array('nid' => 3, 'type' => 'post')),
    '#view_mode' => NULL,
    '#bundle' => NULL,
  );

  $items['comment'] = array(
    'title' => t('Comment'),
    'content' => backdrop_render($render),
    'group' => t('Comment'),
  );

  return $items;
}
